#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fo(i,n) for (i = 0; i < n; i++)

int ar[100024];
string get_ans(int n){
	sort(ar, ar + n);
	for (int i = 0; i < n - 2; i++){
		int a = ar[i];
		int b = ar[i + 1];
		int c = ar[i + 2];
		if(a + b > c and a + c > b and b + c > a){
			return "YES\n";
		}
	}
	return "NO\n";
}

int main(){
	int n, m, a, b, k, l, r;
	cin >> n;
	fo(l, n) cin >> ar[l];
	string can_choose = get_ans(n);
	cout << can_choose;
}

