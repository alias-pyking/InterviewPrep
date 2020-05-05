#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll bigmod(ll b, ll p, ll m){
	if(p == 0){
		return 1;
	}
	if(p % 2 == 0){
		ll value = bigmod(b, p / 2, m);
		return (value * value) % m;
	} else{
		ll x = b % m;
		ll y = bigmod(b, p - 1, m);
		return (x * y) % m;
	}
}
int main(){
	ll b,p,m;
	while(cin >> b >> p >> m){
		cout << bigmod(b, p, m)<<"\n";
	}
}