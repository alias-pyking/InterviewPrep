#include<bits/stdc++.h>
using namespace std;

int sub_arrays_with_given_sum(vector<int> &A, int k){
	int n = A.size();
	int prefix_sum = 0, result = 0;
	unordered_map<int, int> arr_sums;
	arr_sums.insert({0, 1});
	for (int i = 0; i< n; i++){
		prefix_sum += A[i];
		if(arr_sums.find(prefix_sum - k) != arr_sums.end()){
			result += arr_sums[prefix_sum - k];
		}
		arr_sums[prefix_sum]++;
	}
	return result;
}

int main(){
	vector<int> A = {8, -3, -5, 12, 9, -6, -3, -12, 90, -90};
	cout << sub_arrays_with_given_sum(A, 10) << '\n';
	return 0;
}