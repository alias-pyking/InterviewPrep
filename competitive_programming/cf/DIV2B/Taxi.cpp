#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fo(i,n) for (i = 0; i < n; i++)
int n, m, i, j, k;
int a[1000000];

int main(){
	ll a, b, c,d;
	cin >> a >> b >> c >> d;
	int t = 0;
	while(true){
		if(a + b* t >= c - d*t){
			cout << a + b * t << "\n";
			break;
		}
		if(c - d*t <= a + b*(t+1)){
			cout << c - d*t <<"\n";
			break;
		}
		t++;
	}
}