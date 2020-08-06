#include<bits/stdc++.h>
using namespace std;

int max_sub_square(vector<vector<int>> &A){
	int n = A.size(), m = A[0].size();
	int dp[n][m], maxi = 0;
	for(int i = 0; i < n; i++){ 
		dp[i][0] = A[i][0];
		if(dp[i][0] == 1){ 
			maxi = 1;
		}
	}
	for(int j = 0; j < m; j++){ 
		dp[0][j] = A[0][j];
		if (dp[0][j] == 1) maxi = 1;
	}

	for(int i = 1; i < n; i++){ 
		for(int j = 1; j < m; j++){ 
			if(A[i - 1 ][j - 1] == 0) { 
				dp[i][j] = 0;
			} else { 
				dp[i][j] = 1 + min(dp[i - 1][j], min(dp[i - 1][j -1], dp[i][j -1]));
				if (dp[i][j] > maxi) maxi = dp[i][j];
			}
		}
	}
	return maxi*maxi;
}

int main(){

}