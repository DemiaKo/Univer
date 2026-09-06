def fac1(n):
    ret = 1
    for i in range(1,  n+1):
        ret *= i
    return ret

def fac2(n):
    if (n == 0):
        return 1
    return n*fac2(n-1)

def fib1(n):
    if (n == 0):
        return 0
    elif (n == 1):
        return 1
    return fib1(n-1)+fib1(n-2)

def fib2(n):
    f = 1
    s = 1
    t = 0
    for i in range(1, n-1):
        t = s + f
        f = s
        s = t
    return t        

print(fib2(2))