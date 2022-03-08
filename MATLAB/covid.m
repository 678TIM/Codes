function covid()
    % comment out the provinces you are NOT gonna use
    Hubei();
    Guangdong();
    Henan();
    Hunan();
end

function Hubei()
    y = csvread('Hubei.csv');
    t = (1:57)';
    plot(t,y,'bo'); hold on;
    xlabel('Days');
    ylabel('Number of infected');
    theta = [67800 20 4.3]'; % theta(2) = 20 for Hubei, 14 for Henan, 13 for Guangdong and Hunan
    %% Gauss-Newton Method
    while (1)
        r = error(t,y,theta);
        J = Jacobian(t,theta);
        theta_n = theta - (J'*J)\(J'*r);
        if abs(theta_n - theta) < 1E-6
            disp(theta_n);
            break;
        else
            theta = theta_n;
        end
    end
    t = 1:0.1:57;
    y = theta(1)./(1+exp((theta(2)-t)/theta(3)));
    plot(t,y,'b-');
end

function Guangdong()
    y = csvread('Guangdong.csv');
    t = (1:57)';
    plot(t,y,'ro'); hold on;
    xlabel('Days');
    ylabel('Number of infected');
    theta = [1370 13 3.6]'; % theta(2) = 20 for Hubei, 14 for Henan, 13 for Guangdong and Hunan
    %% Gauss-Newton Method
    while (1)
        r = error(t,y,theta);
        J = Jacobian(t,theta);
        theta_n = theta - (J'*J)\(J'*r);
        if abs(theta_n - theta) < 1E-6
            disp(theta_n);
            break;
        else
            theta = theta_n;
        end
    end
    t = 1:0.1:57;
    y = theta(1)./(1+exp((theta(2)-t)/theta(3)));
    plot(t,y,'r-');
end

function Henan()
    y = csvread('Henan.csv');
    t = (1:57)';
    plot(t,y,'go'); hold on;
    xlabel('Days');
    ylabel('Number of infected');
    theta = [1273 14 3.7]'; % theta(2) = 20 for Hubei, 14 for Henan, 13 for Guangdong and Hunan
    %% Gauss-Newton Method
    while (1)
        r = error(t,y,theta);
        J = Jacobian(t,theta);
        theta_n = theta - (J'*J)\(J'*r);
        if abs(theta_n - theta) < 1E-6
            disp(theta_n);
            break;
        else
            theta = theta_n;
        end
    end
    t = 1:0.1:57;
    y = theta(1)./(1+exp((theta(2)-t)/theta(3)));
    plot(t,y,'g-');
end

function Hunan()
    y = csvread('Hunan.csv');
    t = (1:57)';
    plot(t,y,'co'); hold on;
    xlabel('Days');
    ylabel('Number of infected');
    theta = [1018 13 3.4]'; % theta(2) = 20 for Hubei, 14 for Henan, 13 for Guangdong and Hunan
    %% Gauss-Newton Method
    while (1)
        r = error(t,y,theta);
        J = Jacobian(t,theta);
        theta_n = theta - (J'*J)\(J'*r);
        if abs(theta_n - theta) < 1E-6
            disp(theta_n);
            break;
        else
            theta = theta_n;
        end
    end
    t = 1:0.1:57;
    y = theta(1)./(1+exp((theta(2)-t)/theta(3)));
    plot(t,y,'c-');
end

function r = error(t,y,theta)
    r = (theta(1)./(1+exp((theta(2)-t)/theta(3))))-y;
end

function J = Jacobian(t,theta)
    A = 1./(1+exp((theta(2)-t)/theta(3)));
    mu_num = exp((theta(2)-t)/theta(3))*theta(1);
    mu_denom = theta(3)*(1+exp((theta(2)-t)./theta(3))).^2;
    mu = -(mu_num./mu_denom);
    sigma_num = exp((theta(2)-t)./theta(3))*theta(1).*(t-theta(2));
    sigma_denom = (theta(3)^2)*(1+exp((theta(2)-t)./theta(3))).^2;
    sigma = -(sigma_num./sigma_denom);
    J = [A mu sigma];
end
