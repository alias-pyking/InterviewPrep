#include<bits/stdc++.h>
using namespace std;
int dp[2000][2000];
int f(vector<vector<int>> &A, int r, int c,int n , int m) {
	if(r >= n or c >= m)return 1e9;
	if(r == n - 1 and c == m - 1)  return A[r][c];
	if(dp[r][c] != -1) return dp[r][c];
	int t1 = A[r][c] + f(A, r + 1, c, n, m);
	int t2 = A[r][c] + f(A, r, c + 1, n, m);
	return dp[r][c] = min(t1, t2);
}

int min_path(vector<vector<int>> &A) {
	int n = A.size(), m = A[0].size();
	memset(dp, -1, sizeof(dp));
	return f(A, 0, 0, n, m);
}

int main () {

}