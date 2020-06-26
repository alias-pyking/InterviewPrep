#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int nchoc(int A, vector<int> &B) {
	priority_queue<int> max_heap;
	for(auto choc : B){
		max_heap.push(choc);
	}
	unsigned long long int ans = 0;
	int n = B.size();
	while(A--){
		unsigned long long int largest = max_heap.top();
		ans += largest;
		ans %= mod;
		max_heap.pop();
		max_heap.push(largest / 2);
	}
	return ans % mod;
}

int main(){

}