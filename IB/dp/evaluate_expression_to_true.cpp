#include<bits/stdc++.h>
using namespace std;
const int mod = 1e3 + 3;
int dp[500][500][2];
int f(string expression, int i, int j, bool flag) {
	if(i > j) return 0;
	if (i == j){
		if(flag) expression[i] == 'T';
		else expression[i] == 'F';
	}
	if(dp[i][j][flag] != -1) return dp[i][j][flag];
	int ans = 0;
	for (int k = i + 1; k <= j - 1; k += 2) {
		int lt = f(expression, i, k - 1, true);
		int lf = f(expression, i, k - 1, false);
		int rt = f(expression, k + 1, j, true);
		int rf = f(expression, k + 1, j, false);
		if(expression[k] == '&') {
			if(flag) ans += lt * rt, ans %= mod;
			else
				ans += lf * rt + lt * rf + lf * rf, ans %= mod;
		} else if(expression[k] == '|') {
			if(flag) ans += lt*rt + lt * rf + lf*rt, ans %= mod;
			else ans += lf*rf, ans %= mod;
		}
		else {
			if(flag) ans += lf*rt + lt*rf, ans %= mod;
			else ans += lt*rt + lf * rf, ans %= mod;
		}
	}
	return dp[i][j][flag] = ans;
}

int cnttrue(string expression){
	memset(dp, -1, sizeof(dp));

}

int main(){

}