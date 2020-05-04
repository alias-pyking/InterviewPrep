#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fo(i,n) for (i = 0; i < n; i++)
int n, m, i, j, k;
int a[124];
int main(){
	int idx;
	cin >> n >> idx;
	fo(i,n) cin >> a[i];
	idx--;
	int ans = a[idx];
	j = idx - 1;
	i = idx + 1;
	for(; i < n or j >= 0;){
		if(j < 0){
			ans += a[i];
		} else if(i >= n){
			ans += a[j];
		} else if (a[i] == 1 and a[j] == 1){
			ans += 2*a[i];
		}
		i++, j--;

	}
	cout << ans << "\n";
}