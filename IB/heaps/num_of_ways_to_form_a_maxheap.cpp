#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
long long int ncr[124][124];
long long int C(int n, int r){
	if(r > n) return 0;
	if(n <= 1) return 1;
	if(r == 0) return 1;
	if(ncr[n][r] != -1) return ncr[n][r];
	ncr[n][r] = (C(n - 1, r - 1) %mod + C(n - 1, r) %mod);
	ncr[n][r] %= mod;
	return ncr[n][r];
}
long long int L(int n){
	if(n == 1) return 0;
	long long int h = (long long int)log2(n);
	long long int max_nodes_at_h = 1 << h;
	long long int actual_nodes_at_h = n - ((1 << h) - 1);
	if(actual_nodes_at_h >= max_nodes_at_h/2){
		return ((1 << h) - 1)%mod;
	}
	return ((1 << h) - 1 - (max_nodes_at_h / 2 - actual_nodes_at_h))%mod;
}
long long int f(int n, long long int *dp){
	if(n <= 1) return 1;
	if(dp[n] != -1){
		return dp[n];
	}
	long long int l = (long long int)L(n);
	dp[n] = (long long int)((C(n - 1, l)%mod * f(l, dp) %mod) %mod * f(n - 1 - l, dp) %mod)%mod;
	dp[n] %= mod;
	return dp[n];
}
int solve(int A) {
	long long int dp[124];
	for (int i = 0; i <= A; i++){
		dp[i] = -1;
	}
	for (int i = 0; i <= A; i++){
		for (int j = 0; j <= A; j++){
			ncr[i][j] = -1;
		}
	}
	int ans = f(A, dp);
	return ans;
}
