#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fo(i,n) for (i = 0; i < n; i++)
ll n, m, i, j, k;
int main(){
	while(1){
		cin >> n >> m;
		if(n == 0 and m == 0){
			break;
		}
		vector<int> nums;
		for (i = n - m + 1; i <= n; i++){
			nums.push_back(i);
		}
		vector<int> nums1;
		for (i = 1; i <= m; i++){
			nums1.push_back(i);
		}
		int deno_size = nums1.size();
		int nume_size = nums.size();
		for (i = 0; i < deno_size; i++){
			for (j = 0; j < nume_size; j++){
				if(nums1[i] != 1 and nums[j] % nums1[i] == 0){
					nums[j] = nums[j] / nums1[i];
					nums1[i] = 1;
				}
			}
		}
		ll N = 1;
		ll D = 1;
		for (i = 0; i < nume_size; i++){
			N = N * nums[i];
		}
		for (i = 0; i < deno_size; i++){
			D = D * nums1[i];
		}
		cout << n <<" things taken "<<m<<" at a time is "<<N/D<<" exactly.\n";
	}
}