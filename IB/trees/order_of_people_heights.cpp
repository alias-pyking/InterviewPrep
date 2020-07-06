#include <bits/stdc++.h>
using namespace std;
vector<int> order(vector<int> &heights, vector<int> &infronts){
	vector<pair<int, int>> vec;
	int n = heights.size();
	for (int i = 0; i < n; i++){
		vec.push_back({heights[i], infronts[i]});
	}
	sort(vec.begin(), vec.end());
	vector<int> ans(heights.size());
	vector<int> aux;
	for (int i = 0; i < n; i++){
		aux.push_back(i);
	}
	// Heights : 1 2 3 4 5 6
	// Infronts: 3 2 1 2 0 0
	// -1, 3, 2, 1, -1, -1
	for (int i = 0; i < n; i++){
		ans[aux[vec[i].second]] = vec[i].first;
		aux.erase(aux.begin() + vec[i].second);
	}
	return ans;
}
int main(){
	int t, q;
}

