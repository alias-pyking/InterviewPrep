#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fo(i,n) for (i = 0; i < n; i++)

int ar[100024];


int main(){
	int p, q, l, r;
	cin >> p >> q >> l >> r;
	int a, b, c[q], d[q];
	int t[2024];
	memset(t, 0, sizeof t);
	for (int i = 0; i < p; i++){
		cin >> a >> b;
		for (int k = a; k <= b; k++){
			t[k] = 1;
		}
	}
	for (int i = 0; i < q; i++){
		cin >> c[i] >> d[i];
	}
	int slot = 0;
	for (int i = l; i <= r; i++){
		bool flag = true;
		for (int j = 0; j < q and flag; j++){
			for (int k = c[j] + i; k <= d[j] + i; k++){
				if(t[k]){
					flag = false;
					break;
				}
			}
		}
		if(!flag)
			slot++;
	}
	printf("%d\n", slot);
}
