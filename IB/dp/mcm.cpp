#include<bits/stdc++.h>
using namespace std;

int dp[1024][1024];
int mcm(int *a, int i, int j) {
	if(i >= j) return dp[i][j] = 0;
	if(dp[i][j] != -1) return dp[i][j];
	int p_ans = INT_MAX;
	for (int k = i; k < j; k++) {
		int t_ans = mcm(a, i, k) + mcm(a, k + 1, j) + (a[i - 1] * a[k] * a[j]);
		p_ans = min(t_ans, p_ans);
	}
	return dp[i][j] = p_ans;
}

int main () {
	int n;
	cin >> n;
	memset(dp, -1, sizeof(dp));
	int a[n];
	for (int i = 0; i < n; i++) cin >> a[i];
	cout << mcm(a, 1, n - 1);
}