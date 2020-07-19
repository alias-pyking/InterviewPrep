#include<bits/stdc++.h>
using namespace std;
bool match(string s, string t){
    int n = s.length(), m = t.length();
    bool dp[n + 1][m + 1];
    memset(dp, false, sizeof(dp));
    dp[0][0] = true;    
    
    for(int j = 1; j <= m; j++){
        if(t[j - 1] == '*'){
            dp[0][j] = dp[0][j - 1];
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(s[i - 1] == t[j - 1] or t[j - 1] == '?'){
                dp[i][j] = dp[i - 1][j - 1];
            } else if(t[j] == '*'){
                dp[i][j] = dp[i - 1][j] or dp[i][j - 1];
            } else {
                dp[i][j] = false;
            }
        }
    }
    return dp[n][m];
} 