coins=[25,7,10,1]
def makechange(c):
    if c is 0:
        return 0
    minCoins=278947392
    for coin in coins:
        if c-coin>=0:
            currentMinCoins=makechange(c-coin)
            if currentMinCoins<minCoins:
                minCoins=currentMinCoins
    return minCoins+1
print(makechange(49))

