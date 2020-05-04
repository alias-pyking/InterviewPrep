#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fo(i,n) for (i = 0; i < n; i++)
ll n, m, i, j, k;
ll h[100024];


int main(){
	cin >> n;
	for (i = 0; i < n; i++){
		cin >> h[i];
	}
	ll d = h[0];
	ll e = 0;
	for (i = 0; i < n - 1; i++){
		if(h[i] >= h[i + 1]){
			e += h[i] - h[i + 1];
		} else{
			if(e >= h[i + 1] - h[i]){
				e -= h[i + 1] - h[i];
			} else{
				d += (h[i + 1] - h[i]) - e;
				e = 0;
			}
		}
	}
	cout << d << "\n";
}