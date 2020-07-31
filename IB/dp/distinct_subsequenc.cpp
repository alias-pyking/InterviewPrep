#include<bits/stdc++.h>
using namespace std;

int num_distinct(string x, string y){
    int n = x.length(), m = y.length();
    int dp[n + 1][m + 1];
    memset(dp, 0, sizeof(dp));
    for(int i = 0; i <= n; i++){
        dp[i][0] = 1;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(x[i - 1] == y[j - 1]){
                dp[i][j] += dp[i - 1][j] + dp[i - 1][j - 1];
            } else{
                dp[i][j] += dp[i - 1][j];
            }
        }
    }
    return dp[n][m];
}

int main(){

}