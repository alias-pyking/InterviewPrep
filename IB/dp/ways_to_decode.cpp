#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int ways(string s){
    int n = s.length();
    if(s[0] == '0') return 0;
    int dp[n + 1];
    dp[0] = 1;
    dp[1] = 1;
    for(int i = 2; i <= n; i++){
        dp[i] = 0;
        if(s[i - 1] > '0'){
            dp[i] += dp[i - 1]%mod;
        }
        if(s[i - 2] == '1' or (s[i - 2] == '2' and s[i - 1] < '7')){
            dp[i] += dp[i -2] %mod;
        }
        dp[i] %= mod;
    }
    return dp[n];
}
int num_ways(string s){

}

int main(){

}