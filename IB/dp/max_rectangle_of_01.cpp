#include<bits/stdc++.h>
using namespace std;

int largest_rectangle(vector<int> h) {
	stack<int> hist_indexes;
	h.push_back(0);
	int n = h.size(), max_rect = 0;
	for (int i = 0; i < n; i++) {
		while(not hist_indexes.empty() and h[hist_indexes.top()] >= h[i]) {
			int height = h[hist_indexes.top()]; hist_indexes.pop();
			int width;
			if(hist_indexes.empty()) width = i;
			else width = i - hist_indexes.top() - 1;
			max_rect = max(max_rect, width * height);
		}
		hist_indexes.push(i);
	}
	return max_rect;
}
int max_rect_01(vector<vector<int>> &A) {
	vector<int> temp(A[0].size(), 0);
	int n = A.size(), m = A[0].size();
	int max_area = 0;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			if(A[i][j] == 0) temp[j] = 0;
			else temp[j] += A[i][j];
		}
		max_area = max(max_area, largest_rectangle(temp));
	}
	return max_area;
}

int main () {
	vector<vector<int>> A = {{0, 0},
						   {1, 1},
						   {1, 0},
						   {1, 0},
						   {0, 1},
						   {0, 1},
						   {0, 1}};
	cout << max_rect_01(A);
	return 0;
}