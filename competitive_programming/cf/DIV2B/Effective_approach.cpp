#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fo(i,n) for (i = 0; i < n; i++)
int n, m, i, j, b;
int a[100024][2];

int main(){
	memset(a, 0, sizeof a);
	cin >> n;
	fo(i, n) cin >> b, a[b][0]++, a[b][1] = i;
	cin >> m;
	ll vans = 0;
	ll pans = 0;
	for (int i = 0; i < m; i++){
		cin >> b;
		vans += a[b][1] + 1;
		pans += (n - a[b][1]);
	}
	cout << vans<< " " << pans << "\n";
}