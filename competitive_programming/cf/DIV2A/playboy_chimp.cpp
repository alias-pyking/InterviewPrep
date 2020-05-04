#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fo(i,n) for (i = 0; i < n; i++)
int n, k,i, j;
ll q[25024];

struct point2d{
	double x,y;
};
struct rectangle{
	point2d lower;
	point2d upper;
};

int main(){
	cin >> n;
	vector<int> a(n);
	vector<int>::iterator low, up;
	fo(i, n) cin >> a[i];
	cin >> k;
	fo(i, k) cin >> q[i];
	fo(i,k){
		ll h = q[i];
		low = lower_bound(a.begin(), a.end(),h);
		up = upper_bound(a.begin(), a.end(), h);
		if(low - a.begin() == 0){
			cout << "X ";
		} else {
			cout << *(--low) << " ";	
		}
		if(up - a.begin() == n){
			cout << "X\n";
		} else {
			cout << *up << "\n";
		}
	}

}