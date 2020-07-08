#include <bits/stdc++.h>
using namespace std;
int lcs(string x, string y){
	int n = x.length(), m = y.length();
	vector<vector<int>> dp(n + 1, vector<int>(m + 1));
	for(int i = 1; i <=n; i++){
		for (int j = 1; j <= m; j++){
			if(x[i - 1] == y[j - 1]){
				dp[i][j] = 1 + dp[i - 1][j - 1];
			} else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	return dp[n][m];
}

int longest_palindromic_subsequence(string s){
	string x = s;
	reverse(s.begin(), s.end());
	int n = x.length();
	int c = lcs(x, s);
	return (n - (n - c));
}
int main(){
	int t, q;
}

