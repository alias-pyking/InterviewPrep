#include<bits/stdc++.h>
using namespace std;

bool f(vector<int> &A, int i, int n, int p) {
	if(i >= n)  return true;
	if(p <= 0) return false;
	int t1 = f(A, i + p, n, A[min(i + p, n - 1)]);
	int t2 = f(A, i + 1, n, A(min(i + 1, n - 1)));
	return t1 or t2;
}

bool can(vector<int> &A){
	return f(A, 0,A.size(), A[0]);
}

int main() {

}