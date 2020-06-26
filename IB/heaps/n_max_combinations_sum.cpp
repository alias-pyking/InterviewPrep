#include<bits/stdc++.h>
using namespace std;
vector<int> n_max_pairs(vector<int> &A, vector<int> &B){
	priority_queue<pair<int, pair<int, int>>> max_heap;
	set<pair<int, int>> already_present;
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	int n = A.size();
	max_heap.push({A[n - 1] + B[n - 1], {n - 1, n - 1}});
	already_present.insert({n - 1, n - 1});
	vector<int> result;
	for (int cnt = 0; cnt < n; cnt++){
		auto temp = max_heap.top();
		max_heap.pop();
		result.push_back(temp.first);
		int i = temp.second.first, j = temp.second.second;
		int sum = A[i - 1] + B[j];
		auto new_pair = make_pair(i - 1, j);
		auto present = already_present.find(new_pair);
		if( present == already_present.end()){
			max_heap.push({sum, new_pair});
			already_present.insert(new_pair)
		}
		sum = A[i] + B[j - 1];
		new_pair = make_pair(i, j - 1);
		present = already_present.find(new_pair);
		if(present == already_present.end()){
			max_heap.push({sum, new_pair});
			already_present.insert(new_pair);
		}
	}
	return result;
}
int main(){
	
}