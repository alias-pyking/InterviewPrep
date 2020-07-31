#include<bits/stdc++.h>
using namespace std;

int adjacent(vector<vector<int>> &A) {
	int n = A[0].size();
	vector<int> temp(n);
	for(int i =0; i < n; i++){
		temp[i] = max(A[0][i], A[1][i]);
	}
	int c = temp[0], cx = 0, p = temp[0], px = 0;
	int ans = temp[0];
	for(int i = 1; i < n; i++){
		c = px + temp[i];
		cx = p
		ans = max(ans, max(c, cx));
		p = max(c, p);
		px = max(cx, px);
	}

}

int main(){

}