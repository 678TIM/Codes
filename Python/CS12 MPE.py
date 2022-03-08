def differentiate(fxn):
    factors = "" # where we store all the factors of the product
    nums = '1234567890'
    letters = 'aceinost'
    trig = ['sin', 'cos', 'tan', 'sec', 'csc', 'cot']
    if fxn != 'x': # perform chain rule
        i = 0 # get the FIRST instance of '(' and coeffs or trig fxns, if any
        pre = '' # stores the coefficients (if any)
        while i < len(fxn):
            if fxn[i] == '(':
                break
            elif fxn[i] in nums or fxn[i] in letters:
                pre += fxn[i]
                i += 1
        j = len(fxn) - 1 # get the LAST instance of ')' and exponents, if any
        post = ''
        while j > 0:
            if fxn[j] == ')':
                break
            elif fxn[j] in nums or fxn[j] in letters or fxn[j] == '^':
                post = fxn[j] + post # add to the START of post
                j -= 1
        inner = fxn[(i+1):j] # get the function enclosed by the parentheses at index i and j
        # if pre and post are integers, do power rule
        if pre.isnumeric() and '^' in post:
            old_coeff = int(pre)
            old_exp = int(post[1:])
            new_coeff = old_coeff*old_exp
            new_exp = old_exp - 1
            factor = str(new_coeff) + '(' + inner + ')'
            if new_exp != 1: # omit ^1
                factor = factor + '^{}'.format(new_exp)
            factors += factor
        # elif pre is empty but post has integers, do power rule also but set pre as 1
        elif pre == '' and '^' in post:
            old_exp = int(post[1:])
            new_coeff = old_exp
            new_exp = old_exp - 1
            factor = str(new_coeff) + '(' + inner + ')'
            if new_exp != 1: # omit ^1
                factor = factor + '^{}'.format(new_exp)
            factors += factor
        # elif pre is trig fxn and post == '', do trig derivatives
        elif (pre in trig) and (post == ""):
            if pre == 'sin':
                factor = "(cos({}))".format(inner)
            elif pre == 'cos':
                factor = "(-sin({}))".format(inner)
            elif pre == 'tan':
                factor = "(sec({})^2)".format(inner)
            elif pre == 'sec':
                factor = "(sec({})tan({}))".format(inner, inner)
            elif pre == 'csc':
                factor = "(-csc({})cot({}))".format(inner, inner)
            elif pre == 'cot':
                factor = "(-csc({})^2)".format(inner)
            factors += factor
        new_factor = differentiate(inner)

        if new_factor != '1':
            factors = factors + '*' + new_factor
        else:
            factors += ''
    
    if factors == "":
        return '1'
    return factors


# print(differentiate('(x)')) # outputs '1'
# print(differentiate('3(x)^2')) # outputs '6(x)'
# print(differentiate('cos(3(x)^2)')) # outputs '(-sin(3(x)^2))*6(x)'
# print(differentiate('(cos(3(x)^2))^2')) # outputs '2(cos(3(x)^2))*(-sin(3(x)^2))*6(x)'
# print(differentiate('2(cos(3(x)^2))^2')) # outputs '4(cos(3(x)^2))*(-sin(3(x)^2))*6(x)'
# print(differentiate('2(tan(3(x)^2))^2')) # outputs '4(tan(3(x)^2))*(sec(3(x)^2)^2)*6(x)'
# print(differentiate('sin(cos(6(tan(x))^2))'))
# print(differentiate('sin(971(x)^6)'))
# print(differentiate('cos(28657(x)^5)'))
# print(differentiate('tan(177418(x)^4)'))
# print(differentiate('sec(6219404(x)^3)'))
# print("")
# print(differentiate('971(x)^6'))
# print(differentiate('28657(x)^5'))
# print(differentiate('177418(x)^4'))
# print(differentiate('6219404(x)^3'))
# print(differentiate('92460960(x)^7035724'))
# print("")
# print(differentiate('sin(971(x)^6)'))
# print(differentiate('cos(28657(x)^5)'))
# print(differentiate('tan(177418(x)^4)'))
# print(differentiate('sec(6219404(x)^3)'))
# print("")
# print(differentiate('7(sin(971(x)^6))^2'))
# print(differentiate('16(cos(28657(x)^5))^3'))
# print(differentiate('10(tan(177418(x)^4))^4'))
# print("")
# print(differentiate('cos((sin(7(sin(971(x)^6))^2))^7)'))
# print(differentiate('sin((tan(16(cos(28657(x)^5))^3))^7)')) # RECURSION ERROR HERE
# print("")
# print(differentiate('cot(cos(tan(sin(sec(csc(7(x)^3))))))'))
# print(differentiate('tan(sec(sin(cos(cot(csc(7(x)^3))))))'))

print(differentiate('(x)'))
print('1')

print(differentiate('3(x)^2'))
print('6(x)')

print(differentiate('cos(3(x)^2)'))
print('(-sin(3(x)^2))*6(x)')

print(differentiate('(cos(3(x)^2))^2'))
print('2(cos(3(x)^2))*(-sin(3(x)^2))*6(x)')

print(differentiate('2(cos(3(x)^2))^2'))
print('4(cos(3(x)^2))*(-sin(3(x)^2))*6(x)')

print(differentiate('2(tan(3(x)^2))^2'))
print('4(tan(3(x)^2))*(sec(3(x)^2)^2)*6(x)')


print(differentiate('2(x)^2'))
print('4(x)')

print(differentiate('2(sin(2(x)^2))'))
print('(cos(4(x)^2))*8(x)')

print(differentiate('3(x)^2'))
print('6(x)')

print(differentiate('(cos(3(x)^2))^2'))
print('2(cos(3(x)^2))*(-sin(3(x)^2))*6(x)')

print(differentiate('2(cos(3(x)^2))^2'))
print('4(cos(3(x)^2))*(-sin(3(x)^2))*6(x)')

print(differentiate('2(tan(3(x)^2))^2'))
print('4(tan(3(x)^2))*(sec(3(x)^2)^2)*6(x)')

print(differentiate('sin(cos(tan(cot(sec(csc(x))))))'))
print('(cos(cos(tan(cot(sec(csc(x)))))))*(-sin(tan(cot(sec(csc(x))))))*(sec(cot(sec(csc(x))))^2)*(-csc(sec(csc(x)))^2)*(sec(csc(x))tan(csc(x)))*(-csc(x)cot(x))')

print(differentiate('cos(971(x)^971)'))
print('(-sin(971(x)^971))*942841(x)^970')
