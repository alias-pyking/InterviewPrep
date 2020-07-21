#include<bits/stdc++.h>
using namespace std;
bool is_palindrome(string s, int i, int j){
    while(i < j){
        if(s[i] != s[j]) return false;
        i++,j--;
    }
    return true;
}
int min_cut(string s){
    int n = s.length();
    int dp[n][n];
    memset(dp, 0, sizeof(dp));
    for(int i = 0; i < n; i++){
        dp[i][i] = 0; 
    }
    for(int l = 2; l <= n; l++){
        for(int i = 0; i <= n - l; i++){
            int j = i + l - 1;
            if(is_palindrome(s, i, j)){
                dp[i][j] = 0;
            } else {
                dp[i][j] = INT_MAX;
                for(int k = i; k <= j - 1; k++){
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + 1);
                }
            }
        }
    }
    return dp[0][n - 1];
}

int main(){

}