coins=[10,6,1]
def makeChange(c):
    # create and initilize the cache array of size c+1 with -1 at all indeces except -1
    cache=[0]+[-1]*c
    return _makeChange(c,cache)
def _makeChange(c,cache):
    # if the value at cache array is -1 then value is not calculate yet if it is greater 
    # -1 it mean value is calculated and we can use that
    if cache[c]>=0: return cache[c]
    minCoins=2789567
    # remove every coin from the amount
    for coin in coins:
        # skip if the coin is bigger than amount
        if c-coin>=0:
            # Do the same for the rest of the amount
            currentCoins=_makeChange(c-coin,cache)
            if currentCoins<minCoins:
                minCoins=currentCoins
    cache[c]=minCoins+1
    return cache[c]
print(makeChange(509885743))