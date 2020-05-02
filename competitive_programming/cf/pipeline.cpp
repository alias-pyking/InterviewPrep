#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fo(i,n) for (i = 0; i < n; i++)
ll n, k;

ll sum(ll n){
	return (n * (n + 1)) / 2;
}
ll sum(ll s, ll e){
	if(s <= 1){
		return sum(e);
	}
	return sum(e) - sum(s - 1);
}
ll min_splitters(ll n, ll k){
	ll st = 1, en = k;
	while(st < en){
		ll mid = (st + en) / 2;
		ll s = sum(mid, k);
		if(s == n){
			return k - mid + 1;
		}
		if (s > n){
			st = mid + 1;
		} else{
			en = mid;
		}
	}
	return k - st + 2;
}
int main(){
	cin >> n >> k;
	if(n == 1){
		cout << 0 << "\n";
	} else if( n <= k){
		cout << 1 << "\n";
	} else{
		k--, n--;
		if(sum(k) < n){
			cout << -1 << "\n";
		} else{
			cout << min_splitters(n, k) << "\n";
		}
	}
	
}