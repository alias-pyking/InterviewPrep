#include<bits/stdc++.h>
using namespace std;

int interleaved(string A, string B, string C){
    int n = A.length(), m = B.length();
    bool dp[n + 1][m + 1];
    memset(dp, 0, sizeof(dp));
    if(n + m != C.length()){
        return false;
    }
    for(int i = 0; i <=n; i++){
        for(int j = 0; j <= m; j++){
            int k = i + j - 1;
            if(i == 0 and j == 0) dp[i][j] = true;
            else if(i == 0){
                if(B[j - 1] == C[j - 1]) dp[i][j] = dp[i][j - 1];
            } else if(j == 0){
                if(A[i - 1] == C[i - 1]) dp[i][j] = dp[i - 1][j];
            }
            else if(A[i - 1] == C[k] and B[j - 1] != C[k]) dp[i][j] = dp[i - 1][j];
            else if(A[i - 1] != C[k] and B[j - 1] == C[k]) dp[i][j] = dp[i][j - 1];
            else if(A[i - 1] == C[k] and B[j  - 1] == C[k]) dp[i][j] = dp[i - 1][j] or dp[i][j - 1];
        }
    }
    return dp[n][m];
}

int main(){

}