#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fo(i,n) for (i = 0; i < n; i++)

int ar[100024];


int main(){
	int n, m, k;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> ar[i];
	}
	double r1 = *max_element(ar, ar + n);
	cin >> m;
	for (int i = 0; i < m; i++){
		cin >> ar[i];
	}
	double p1 = *max_element(ar, ar + m);
	cin >> k;
	for (int i = 0; i < k; i++){
		cin >> ar[i];
	}
	double p2 = *min_element(ar, ar + k);
	int A, B;
	cin >> A >> B;
	double ans = ((double)B * p1 * r1 * r1 )/ ((double)A * p2 + B * p1)	;
	cout << setprecision(9) << sqrt(ans) << "\n";
}
