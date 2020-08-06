#include<bits/stdc++.h>
using namespace std;

int find(int r_x, int r_y, vector<string> &A, int n, int m){
	int X[8] = {0, -1, -1,-1, 0, 1, 1, 1};
	int Y[8] = {1, 1, 0, -1, -1, -1, 0, 1};
	int count = 0;
	for (int i = 0; i < 8; i++){
		int x = r_x;
		int y = r_y;
		while(x < n and y < m and x >= 0 and y >= 0){
			x += X[i];
			y += Y[i];
			if(x < n and y < m and x >= 0 and y >= 0 and A[x][y] == '1'){
				count++;
				break;
			}
		}
	}
	return count;
}

vector<vector<int>> queenAttack(vector<string> &A){
	int n = A.size();
	int m = A[0].size();
	vector<vector<int>> ans(n, vector<int>(m));
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			ans[i][j] = find(i, j, A, n, m);
		}
	}
	return ans;
}

int main() {

}