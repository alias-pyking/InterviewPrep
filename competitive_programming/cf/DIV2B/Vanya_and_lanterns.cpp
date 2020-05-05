#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fo(i,n) for (i = 0; i < n; i++)
int n, m, i, j, k;
double a[1024];

struct point2d{
	double x,y;
};
struct rectangle{
	point2d lower;
	point2d upper;
};
int main(){
	int l;
	cin >> n >> l;
	fo(i, n) cin >> a[i];
	sort(a, a + n);
	double max_distance = 0;
	for (i = 1; i < n; i++){
		max_distance =(double)max(max_distance, (double)a[i] - a[i - 1]);
	}
	max_distance /= 2;
	int left_l = a[0];
	int right_l = l - a[n - 1];
	if(left_l > max_distance){
		max_distance = left_l;
	}
	if(right_l > max_distance){
		max_distance = right_l;
	}
	cout<< setprecision(9) << max_distance << "\n";
}