#include<iostream>
using namespace std;

int las(vector<int> &A) {
	int n = A.size();
	sort(A.begin(), A.end());
	int dp[n][n];
	if(n <= 2) return n;
	int best = 2;
	for(int i = 0; i < n; i++){
		dp[i][n - 1] = 2;
	}
	for(int j = n - 2; j > 0; j--) {
		int i = j - 1, k = j + 1;
		while(i >= 0 and k < n) {
			if(A[i] + A[k] < 2*A[j]) k++;
			else if(A[i] + A[k] > 2*A[j]) {
				dp[i][j] = 2;
				i--;
			} else {
				dp[i][j] = dp[j][k] + 1;
				best = max(best, dp[i][j]);
				i--, k++;
			}
		}
		while(i >= 0) {
			dp[i][j] = 2;
			i--;
		}
	}
	return best;
	
}

int main() {

}