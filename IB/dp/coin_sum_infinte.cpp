#include<bits/stdc++.h>
using namespace std;
const int N = 1e4+24;
const int mod = 1000007;

int coin_change2(vector<int> &coins, int n){
	int m = coins.size();
	int dp[n + 1][m + 1];
	for(int j = 0; j <= m; j++){
		dp[0][j] = 1;
	}
	for(int i = 0; i <= n; i++){
		dp[i][0] = 0;
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(i - coins[j - 1] >= 0){
				dp[i][j] = (dp[i][j - 1] % mod + dp[i - coins[j - 1]][j] % mod)%mod;
			} else {
				dp[i][j] = dp[i][j - 1] % mod;
			}
		}
	}
	return dp[n][m] % mod;
}
int coin_change2_on(vector<int> &coins, int n){
	int dp[n + 1], m = coins.size();
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;
	for(int i = 0; i < m; i++){ 
		for(int j = coins[i]; j <= n; j++){ 
			dp[j] += dp[j - coins[i]];
			dp[j] %= mod;
		}
	}
	return dp[n]%mod;
}

int main(){
	vector<int> A = {1,2,3};
	cout << coin_change2(A,4) << '\n';
	return 0;
}
