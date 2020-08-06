#include<bits/stdc++.h>
using namespace std;
const int N = 1e4+24;
const int mod = 1e9 + 7;
int dp[N][N];
int coin_sum_helper(vector<int> &coins, int m, int n){
	if(n == 0) return 1;
	if(n > 0 and m <= 0) return 0;
	if(n < 0) return 0;
	if(dp[n][m] != -1 ) return dp[n][m];
	return dp[n][m] = coin_sum_helper(coins, m - 1, n) + coin_sum_helper(coins, m, n - coins[m - 1]);
}
int coin_change2(vector<int> &A, int n){
	int m = A.size();
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
				dp[i][j] = dp[i][j - 1] + dp[i - coins[j - 1]][j];
			} else {
				dp[i][j] = dp[i][j - 1];
			}
		}
	}
	return dp[n][m];
}

int main(){
	vector<int> A = {1,2,3};
	cout << coin_change2(A,4) << '\n';
	return 0;
}
