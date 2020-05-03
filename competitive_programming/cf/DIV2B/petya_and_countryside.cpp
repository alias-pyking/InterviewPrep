#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fo(i,n) for (i = 0; i < n; i++)
int n, m, i, j, k;
int a[1024];
int main(){
	cin >> n;
	fo(i,n)cin >> a[i];
	int ans = 0;
	fo(i,n){
		j = i - 1;
		k = i + 1;
		int t1 = 0;
		int t2 = 0;
		while(j >= 0 and a[j] <= a[j + 1]){
			t1++,j--;
		}
		while( k < n and a[k] <= a[k -1]){
			t2++, k++;
		}
		ans = max(ans, t1 + 1 + t2);
	}
	cout << ans << "\n";
}