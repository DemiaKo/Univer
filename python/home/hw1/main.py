def fib1(n, memo = None):
    if (memo == None):
        memo = {0: 0, 1: 1}
    if n in memo:
        return (memo[n])
    memo[n] = fib1(n-1, memo) + fib1(n-2, memo)
    return (memo[n])

def fib2(n):
    if n == 0:
        return (0)
    a, b = 0, 1
    for i in range(2, n+1):
        a, b = b, a + b
    return(b)
    

print(fib2(10))

