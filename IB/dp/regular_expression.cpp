#include<bits/stdc++.h>
using namespace std;

bool regx_match(string str, string pattern){
    int n = str.length(), m = pattern.length();
    bool dp[n + 1][m + 1];
    memset(dp, false, sizeof(dp));
    dp[0][0] = true;
    for(int i = 1; i <= n; i++) dp[i][0] = false;
    for(int j = 1; j <= m; j++){
        if(pattern[j - 1] == '*') dp[0][j] = dp[0][j - 2];
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(pattern[j - 1] == '.' or str[i - 1] == pattern[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else if(pattern[j - 1] == '*'){
                if(dp[i][j - 2]){
                    dp[i][j] = dp[i][j - 2];
                } else if(pattern[j - 2] == str[i - 1]) {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
    }
    return dp[n][m];
}

int main() {

}