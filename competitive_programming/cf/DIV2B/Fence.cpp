#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fo(i,n) for (i = 0; i < n; i++)

int main(){
	int n, k;
	int arr[150002] = {0};
	cin >> n >> k;
	int idx, min_sum = INT_MAX;
	for (int i = 1; i <= n; i++){
		cin >> arr[i];
		arr[i] += arr[i - 1];
	}
	for (int i = k; i <= n; i++){
		if(min_sum > arr[i] - arr[i - k]){
			min_sum = arr[i] - arr[i - k];
			idx = i;
		}
	}
	cout << idx - k + 1 << "\n";
}