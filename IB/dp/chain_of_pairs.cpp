#include<bits/stdc++.h>
using namespace std;

int f(pair<int, int> prev,vector<vector<int>> &A, int n, int i = 0){
	if (i >= n) return 0;
	if(prev.second >= A[i][0]){ 
		return f(prev, A, n, i + 1);
	}
	int t1 = 1 + f({ A[i][0], A[i][1] }, A, n, i + 1);
	int t2 = f(prev, A, n, i + 1);
	return max(t1, t2);
}

int solve(vector<vector<int>> &A){
	int n = A.size();
	vector<int> dp(n, 0);
	for(int i = 0; i < n; i++){ 
		dp[i] = 1;
		for(int j = i - 1; j >= 0; j--){ 
			if(A[j][1] < A[i][0] and dp[i] < dp[j] + 1){ 
				dp[i] = dp[j] + 1;
			}
		}
	}
	return *max_element(dp.begin(), dp.end());
}

int main(){

}