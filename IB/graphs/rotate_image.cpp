#include<bits/stdc++.h>
using namespace std;
// rotate N X N matrix anti clockwise
void rotate_matrix(vector<vector<int>> A){
	int N = A.size();
	for (int i = 0; i < N / 2; i++){
		for (int j = i; j < N - i - 1; j++){
			int temp = A[i][j];
			A[i][j] = A[j][N - i - 1];
			A[j][N - i - 1] = A[N - i - 1][N - j - 1];
			A[N - i - 1][N - j - 1] = A[N - j - 1][i];
			A[N - j - 1][i] = temp;
		}
	}
	return;
}

int main(){

}