#include<bits/stdc++.h>
using namespace std;

int dp[1000][1000];
int f(int l, int r, vector<int> &A){
	if(l > r) return 0;
	if(dp[l][r] != -1) return dp[l][r];
	int left = A[l] + min(f(l + 2, r, A), f(l + 1, r - 1, A));
	int right = A[r] + min(f(l + 1, r - 1, A), f(l, r - 2, A));
	return dp[l][r] = max(left, right);
}
int maxcoin(vector<int> &A){
	memset(dp, -1, sizeof(dp));
	int ans = f(0, A.size() - 1, A);
	return ans;
}
int main() {

}