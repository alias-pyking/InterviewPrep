#include<bits/stdc++.h>
using namespace std;

int zero_sum(vector<int> &A){
	int n = A.size();
	int prefix_sum = 0, result = 0;
	unordered_map<int, int> arr_sums;
	for (int i = 0; i< n; i++){
		prefix_sum += A[i];
		if(prefix_sum == 0){ 
			result++;
		}
		if(arr_sums.find(prefix_sum) != arr_sums.end()){ 
			result += arr_sums[prefix_sum];
		}
		arr_sums[prefix_sum]++;
	}
	return result;
}

int solve(vector<vector<int>> &A){
	int n = A.size(), m = A[0].size();
	if (n == 0 or m == 0) return 0;
	int ans = 0;
	for(int i = 0; i < m; i++){ 
		vector<int> arr(n, 0);
		for(int j = i; j < m; j++){ 
			for(int k = 0; k < n; k++){ 
				arr[k] += A[k][j];
			}
			ans += zero_sum(arr);
		}
	}
	return ans;
}

int main(){

}