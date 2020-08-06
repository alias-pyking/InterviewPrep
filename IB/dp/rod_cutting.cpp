#include<bits/stdc++.h>
using namespace std;
const int N = 1e5;
bool should_cut[N];
vector<vector<int>> dp, parent;
vector<int> ans;
vector<int> arr;
int min_cost(int st, int en){
	if(st + 1 >= en) return 0;
	if(dp[st][en] != -1) return dp[st][en];
	int min_sub_cost = INT_MAX;
	int index = -1;
	for (int c = st + 1; c < en; c++) {
			int len = arr[en] - arr[st];
			int cost = len + min_cost(st, c) + min_cost(c, en);
			if(min_sub_cost > cost){
				min_sub_cost = cost;
				index = c;
			}
	}
	parent[st][en] = index;
	return dp[st][en] = min_sub_cost;
}
void back(int st, int en){
	if(st + 1 >= en) return;
	ans.push_back(arr[parent[st][en]]);
	back(st, parent[st][en]);
	back(parent[st][en], en);
}
vector<int> rod_cutting(int l, vector<int> &A){
	arr.clear();
	A.push_back(l);
	A.insert(A.begin(), 0);
	int n = A.size();
	for(auto i: A) arr.push_back(i);
	dp.resize(n);
	parent.resize(n);
	ans.clear();
	for(int i = 0; i < n; i++){
		dp[i].resize(n);
		parent[i].resize(n);
		fill(dp[i].begin(), dp[i].end(), -1);
	}
	min_cost(0, n - 1);
	back(0, n - 1);
	return ans;
}



int main() {
	int l = 6;
	vector<int> A = {1, 2, 5};
	cout << rod_cutting(l, A) << '\n';
	return 0;
}
