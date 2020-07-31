#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
int solve(int n, int s) {
	long long int dp[n][s];
	if(s < 1 or s > 9*n) return 0;
	for (int j = 0; j < s; j++){
		if(j + 1 <= 9) dp[0][j] = 1;
		else dp[0][j] = 0;
	}
	for (int i = 0; i < n; i++){
		dp[i][0] = 1;
	}
	for (int i = 1; i < n; i++){
		for (int j = 1; j < s; j++) {
			dp[i][j] = 0;
			int k = 0;
			if(j >= 9) k = j - 9;
			for (; k <= j; k++) {
				dp[i][j] += dp[i - 1][k];
				dp[i][j] %= mod;
			}
		}
	}
	return dp[n - 1][s - 1];
}

int main() {

}