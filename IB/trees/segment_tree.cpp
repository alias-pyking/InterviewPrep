#include <bits/stdc++.h>
using namespace std;
void construct_segment_tree(vector<int> &input, int *segment_tree, int low, int high, int pos){
	if(low == high){
		segment_tree[pos] = input[low];
		return;
	}
	int mid = (low + high) / 2;
	construct_segment_tree(input, segment_tree, low, mid, 2 * pos + 1);
	construct_segment_tree(input, segment_tree, mid+ 1, high, 2 * pos + 2);
	segment_tree[pos] = min(segment_tree[2 * pos + 1], segment_tree[2 * pos + 2]);
}
int range_min_query(int *segment_tree, int q_low, int q_high, int low, int high, int pos){
	if(q_low <= low and high <= q_high){
		return segment_tree[pos];
	}
	if(q_low > high or q_high < low){
		return INT_MAX;
	}
	int mid = (low + high) / 2;
	return min(range_min_query(segment_tree, q_low, q_high, low, mid, 2 * pos + 1),
			   range_min_query(segment_tree, q_low, q_high, mid + 1, high, 2 * pos + 2));
}
int main(){
	int n;
	cin >> n;
	vector<int> input(n);
	int segment_tree[2 * n + 1];
	construct_segment_tree(input, segment_tree, 0, n - 1, 0);
	int t, q;
}

