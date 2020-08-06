#include<bits/stdc++.h>
using namespace std;
int dp[1024][1024];
int kp(vector<int> &v, vector<int> &w, int c, int n){
	if (c < 0 or n < 0) return 0;
	if (dp[n][c] != -1) return dp[n][c];
	if (c - w[n] < 0) return kp(v, w, c, n - 1);
	int t1 = v[n] + kp(v, w, c - w[n], n - 1);
	int t2 = kp(v, w, c, n - 1);
	return dp[n][c] = max(t1, t2);
}

int main(){

}