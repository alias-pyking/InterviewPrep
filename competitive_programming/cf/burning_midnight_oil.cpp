#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fo(i,n) for (i = 0; i < n; i++)
ll n, k;
ll get_lines_of_code(ll v){
	ll ans = v;
	int i = 1;
	while(1){
		ll t = v / pow(k, i);
		if(t == 0){
			break;
		}
		ans += t;
		i++;
	}
	return ans;
}
int main(){
	cin >> n >> k;
	ll st = 1;
	ll en = n;
	ll ans = -1;
	while(st <= en){
		ll v = (st + en) / 2;
		ll loc = get_lines_of_code(v);
		if(loc == n){
			ans = v;
			break;
		}
		else if(loc > n){
			ans = v;
			en = v - 1;
		} else{
			st = v + 1;
		}
	}
	cout << ans << "\n";
}