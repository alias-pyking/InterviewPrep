def countWays(n):
    table={}
    table[0]=1
    table[1]=2
    table[2]=3
    for i in range(3,n+1):
        table[i]=table[i-1]+table[i-2]+table[i-3]
    print(table)
    return table[n]

print(countWays(100))
    


