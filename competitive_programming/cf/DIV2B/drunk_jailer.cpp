#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fo(i,n) for (i = 0; i < n; i++)


struct point2d{
	double x,y;
};
struct rectangle{
	point2d lower;
	point2d upper;
};
int main(){
	int t, n;
	cin >> t;
	while(t--){
		cin >> n;
		char a[n + 1];
		// first round
		int size = n;
		while(size--){
			for (int i = 1; i <= n; i++){
			a[i] = 'u';
			}
			// second round
			for (int i = 2; i <= n; i+=2){
				a[i] = 'l';
			}
			// third round
			for (int i = 3; i <= n; i+=3){
				if(a[i] == 'l'){
					a[i] = 'u';
				} else{
					a[i] = 'l';
				}
			}
		}
		int ans = 0;
		for (int i = 1; i <= n; i++){
			if(a[i] == 'u'){
				ans++;
			}
		}
		cout << ans << "\n";
	}
}