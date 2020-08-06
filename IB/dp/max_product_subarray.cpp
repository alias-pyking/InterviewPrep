#include<bits/stdc++.h>
using namespace std;

int mps(const vector<int> &A){
	int n = A.size();
	if (n == 0) return -1;
	int current_max = A[0];
	int current_min = A[0];
	int global_max = A[0];
	for(int i = 1; i < n; i++){ 
		int temp = current_max;
		current_max =max(max(current_max*A[i], current_min*A[i]),A[i]);
		current_min = min(min(temp*A[i], current_min*A[i]), A[i]);
		global_max = max(current_max, global_max);
	}
	return global_max;
}

int main(){

}