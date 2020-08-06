#include<bits/stdc++.h>
using namespace std;

int f(vector<vector<int>> &A, int i, int j, int n) {
	if(i == n) return 0;
	int t1 = A[i][j] + f(A, i + 1, j, n);
	int t2 = A[i][j] + f(A, i + 1, j + 1, n);
	return max(t1, t2);
}

int max_path(vector<vector<int>> &A){
	return f(A, 0, 0, A.size());	
}

int main () {

}