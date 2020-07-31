#include<bits/stdc++.h>
using namespace std;

int func(vector<int> &A, int n,vector<int> &dp,int i = 0) {
	if(i >= n - 1) return 0;
	if(dp[i] != -1) return dp[i];
	int t1 = 1 +  func(A, n,dp,i + A[i] );
	int t2 = 1 + func(A, n,dp, i + 1);
	return dp[i] = min(t1, t2);
}
int jump(vector<int> &A) {
	// for(auto c: A) {
	// 	cout << c <<" ";
	// }
	// cout << '\n';
	vector<int> dp(A.size(), -1);
	int ans = func(A, A.size(), dp);
	return ans;
}

int main () {
	// cout << "here";
	vector<int> A = {2,1,1};
	cout << jump(A) << '\n';
	return 0;
}