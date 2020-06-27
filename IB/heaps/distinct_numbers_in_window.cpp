#include<bits/stdc++.h>
using namespace std;
vector<int> dNums(vector<int> &A, int B) {
	unordered_map<int, int> count;
	for (int i = 0; i < B; i++){
		count[A[i]]++;
	}
	int left = 0, right = B, n = A.size();
	vector<int> result;
	result.push_back(count.size());
	int current_size = count.size();
	while(right < n){
		if(count[A[left]] > 1){
			count[A[left]]--;
			count[A[right]]++;
			left++, right++;
		} else {
			count.erase(A[left]);
			count[A[right]]++;
			left++, right++;
		}
		result.push_back(count.size());
	}
	return result;
}


int main(){

}