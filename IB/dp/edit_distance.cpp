#include <bits/stdc++.h>
using namespace std;
int minimum_edit_distance(string x,string y){
	int n = x.length(), m = y.length();
	vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
	for (int i = 0; i <= n; i++){
		for (int j = 0; j <= m; j++){
			if(i == 0){
				dp[i][j] = j;
			} else if(j == 0){
				dp[i][j] = i;
			}
		}
	}
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			if(x[i - 1] == y[j - 1]){
				dp[i][j] = dp[i - 1][j - 1];
			} else {
				dp[i][j] = 1 + min(dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	return dp[n][m];
}
int main(){

	int t, q;
}

