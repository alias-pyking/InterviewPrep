#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fo(i,n) for (i = 0; i < n; i++)

int ar[100024];


int main(){
	int w1, w2, n1, n2;
	cin >> w1 >> w2 >> n1 >> n2;
	if(n1 <= n2){
		int ans = w2 + (n2 - n1 - 1) * 2 * w2 + w2 + (n2 - n1 - 1) * w1;
		cout << ans << "\n";
	}
	else{
		int ans = w2 + (n1 - n2 - 1) * 2 * w2 + w2 + (n1 - n2 + 1) * w1;
		cout << ans << "\n";
	}
	return 0;
}