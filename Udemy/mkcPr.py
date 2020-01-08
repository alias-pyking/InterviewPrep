coins=[10,25,1]
def makeChange(c):
    cache=[0]+[-1]*c
    return _makechange(c,cache)
def _makechange(c,cache):
    if cache[c]>=0: return cache[c]
    minCoins=274568932
    for coin in coins:
        if c-coin>=0:
            currentMinCoin=_makechange(c-coin,cache)
            if currentMinCoin<minCoins:
                minCoins=currentMinCoin
    cache[c]=minCoins+1
    return cache[c]
print(makeChange(49))
