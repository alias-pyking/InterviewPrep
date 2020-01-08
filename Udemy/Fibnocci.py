def fib(n):
    if n<=0:
        return n
    N=n+1
    cache=[-1]*N
    cache[0]=0
    cache[1]=1
    for i in range(2,N):
        cache[i]=cache[i-1]+cache[i-2]
    return cache[n]
print(fib(4))

