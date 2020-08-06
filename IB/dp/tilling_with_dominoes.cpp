#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int count_ways(int n){
	int A[n + 1], B[n + 1];
	A[0] = 1, A[1] = 0;
	B[0] = 0, B[1] = 1;
	for(int i = 2; i <= n; i++){ 
		A[i] = (A[i - 2] % mod + 2*B[i - 1] % mod)%mod;
		B[i] = (A[i - 1] % mod + B[i - 2] % mod) % mod;
	}
	return A[n] % mod;
}
int main(){

}