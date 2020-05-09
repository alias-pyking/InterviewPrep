#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fo(i,n) for (i = 0; i < n; i++)
int n, m, i, j, k;
void make_prefix_sum(int *A,vector<ll> prefix_sum, int size){
	ll max_sum = 0;
	for (int idx = 0; i < size; i++){
		max_sum += A[i];
		prefix_sum[i] = max_sum;
	}
}
int main(){
	cin >> n;
	int a[n];
	int b[n];
	fo(i, n) cin >> k, a[i] = k, b[i] = k;
	cin >> m;
	sort(b, b + n);
	ll prefix_sum1[n];
	ll prefix_sum2[n];
	ll max_sum = 0;
	fo(i,n)
		max_sum += a[i], prefix_sum1[i] = max_sum;
	max_sum = 0;
	fo(i, n) max_sum += b[i], prefix_sum2[i] = max_sum;
	while (m--)
	{
		int t, l, r;
		cin >> t >> l >> r;
		l--, r--;
		if (t == 1)
		{
			if (l == 0)
			{
				cout << prefix_sum1[r] << "\n";
			}
			else
			{
				cout << prefix_sum1[r] - prefix_sum1[l - 1] << "\n";
			}
		}
		else
		{
			if (l == 0)
			{
				cout << prefix_sum2[r] << "\n";
			}
			else
			{
				cout << prefix_sum2[r] - prefix_sum2[l - 1] << "\n";
			}
		}
	}
}