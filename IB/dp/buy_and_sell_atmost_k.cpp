#include<bits/stdc++.h>
using namespace std;

int buy_and_sell_k(vector<int> &prices, int k) {
	int n = prices.size();
	int profit[2][n];
	for (int i = 0; i < 2; i++) {
		profit[i][0] = 0;
	}
	for(int j = 0; j < n; j++) {
		profit[0][j] = 0;
	}
	int f = 1;
	for (int i = 1; i <= k; i++)
	{
		int prev_diff = INT_MIN;
		for (int j = 1; j < n; j++)
		{
			prev_diff = max(prev_diff, profit[f^1][j - 1] - prices[j - 1]);
			profit[f][j] = max(profit[f][j - 1], prices[j] + prev_diff);
		}
		f ^= 1;
	}
	return profit[f^1][n - 1];
}

int main () {

}