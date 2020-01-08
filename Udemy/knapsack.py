
wt = [1, 3, 4, 5]
val = [1, 4, 5, 7]
max_wt = 7
dp = [[0] * (max_wt + 1)] * len(val)
for i in range(len(dp)):
    print(dp[i])
for i in range(1,len(dp[0])):
    dp[0][i] = val[0]
for i in range(1,len(dp)):
    for j in range(1, len(dp[0])):
        if (wt[i] <= j):
            dp[i][j] = max(val[i] + \
                 dp[i - 1][j - wt[i]], dp[i - 1][j])


for i in range(len(dp)):
    print(dp[i])
        
print(dp[len(val) - 1][max_wt])