#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fo(i,n) for (i = 0; i < n; i++)
int n, c, i, j,t;
ll pos[100024];
bool F(ll x){
	ll lastpos = pos[0];
	int cowsplaced = 1;
	for(i = 1; i < n; i++){
		if(pos[i] - lastpos >= x){
			if(++cowsplaced == c){
				return true;
			}
			lastpos = pos[i];
		}
	}
	return false;
}

int main(){
	cin >> t;
	while(t--){
		cin >> n >> c;
		fo(i, n) cin >> pos[i];
		sort(pos, pos + n);
		ll st = 0, end = pos[n - 1] - pos[0];
		while(st <= end){
			ll mid = (st + end) / 2 + 1;
			if(F(mid)){
				st = mid;
			} else{
				end = mid - 1;
			}
		}
		cout << st << "\n";
	}
}