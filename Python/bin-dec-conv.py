# UNSIGNED NUMBERS
def dec2bin(num): # passed as string
    s = str(num).split('.')
    whole = int(s[0])
    frac = "0." + s[1]
    # DON'T TOUCH
    pre = ""
    quo = 1
    while quo != 0:
        quo = whole // 2
        rem = whole % 2
        pre = str(rem) + pre
        whole = quo
    # GOOD NA
    post = ""
    num = float(frac)
    res = 0
    while res != 1: # stop when res == 1
        res = num * 2.0
        if res > 1:
            post += "1"
            res -= 1
            num = res
        elif res < 1:
            post += "0"
            num = res
    post += "1" # guaranteed last bit is 1
    return "{}.{}".format(pre, post)

# UNSIGNED NUMBERS
def bin2dec(num): # passed as string
    s = str(num).split('.')
    pre = s[0]
    post = s[1]
    whole = 0
    for i in range(1, len(pre)):
        exp = len(pre)-i
        whole += (2**exp) * int(pre[i-1])
    frac = 0
    for j in range(0, len(post)):
        exp = -1*(j+1)
        frac += (2**exp) * int(post[j])
    return whole + frac


print(dec2bin('59.7313690185546875'))
