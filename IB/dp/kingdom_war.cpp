#include<bits/stdc++.h>
using namespace std;

int kadane_algo(vector<int> &A, int n) {
	int current_max, global_max = A[0];
	current_max = global_max;
	for (int i = 1; i < n; i++){
		current_max = max(A[i], current_max + A[i]);
		global_max = max(global_max, current_max);
	}
	return global_max;
}

int kw(vector<vector<int>> &A) {
	int n = A.size(), m = A[0].size();
	int dp[n][m];
	dp[n - 1][m - 1] = A[n - 1][m - 1];
	int global_max = A[n - 1][m - 1];
	for (int j = m - 2; j >= 0; j++) {
		dp[n - 1][j] = dp[n - 1][j + 1] + A[n - 1][j];
		global_max = max(dp[n - 1][j], global_max);
	}
	for (int i = n - 2; i >= 0; i++) {
		dp[i][m - 1] = dp[i + 1][m - 1] + A[i][n - 1];
		global_max = max(global_max, dp[i][m - 1]);
	}
	for (int i = n - 2; i >= 0; i--) {
		for (int j = m - 2; j >= 0; j--) {
			dp[i][j] = dp[i + 1][j] + dp[i][j + 1] - dp[i + 1][j + 1] + A[i][j];
			global_max = max(global_max, dp[i][j]);
		}
	}
	return global_max;
}

int main() {
	vector<int> A = {-2, 3, 2, -1};
	cout << kadane_algo(A, 0, A.size() - 1);
	return 0;
}