#include <bits/stdc++.h>
using namespace std;
int dp[1024][1024];
int lcs_helper(string x, string y, int i, int j){
	if(i < 0) return 0;
	if(dp[i][j] != -1) return dp[i][j];
	if(x[i] == y[j]){
		dp[i][j] = 1 + lcs_helper(x, y, i - 1, j - 1);
	} else {
		int t1 = lcs_helper(x, y, i, j - 1);
		int t2 = lcs_helper(x, y, i - 1, j);
		dp[i][j] = max(t1, t2);
	}
	return dp[i][j];
}
int lcs(string x, string y){
	int n = x.length(), m = y.length();
	memset(dp, sizeof(dp),-1);
	return lcs_helper(x,y,n - 1, m - 1);
}

int main(){
	int t, q;
}

