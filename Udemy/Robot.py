# Tob down approach
def fib(n):
        N=n+1
        # initializing the cache with -1
        cache=[-1]*N
        # setting the initial values
        cache[0]=0
        cache[1]=1
        return _fib(n,cache)
def _fib(n,cache):
        # if the value is already computed than it will be stored it the cache
        # and the value of cache[i] will be set to the computed value
        if(cache[n]>=0):return cache[n]
        cache[n]=_fib(n-1,cache)+_fib(n-2,cache)
        return cache[n]
print(fib(90))
