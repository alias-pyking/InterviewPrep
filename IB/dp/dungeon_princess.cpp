#include<bits/stdc++.h>
using namespace std;

int min_health(vector<vector<int>> &A){
	int n = A.size(), m = A[0].size();
	int dp[n][m];
	dp[n - 1][m - 1] = A[n - 1][m - 1] > 0 ? 1 : abs(A[n - 1][m - 1]) + 1;
	for (int i = n - 2; i >= 0; i--) {
		dp[i][m - 1] = max(dp[i + 1][m - 1] - A[i][n - 1], 1);
	}
	for (int j = m - 2; j >= 0; j--) {
		dp[n - 1][j] = max(dp[n - 1][j + 1] - A[n - 1][j], 1);
	}
	for (int i = n - 2; i >= 0; i--) {
		for(int j = n - 2; j >= 0; j--) {
			int min_points_on_exit = min(dp[i + 1][j], dp[i][j + 1]);
			dp[i][j] = max(min_points_on_exit - A[i][j], 1);
		}
	}
	return dp[0][0];
}

int main() {

}