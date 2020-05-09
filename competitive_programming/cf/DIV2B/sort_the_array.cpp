#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fo(i,n) for (i = 0; i < n; i++)
int n, m, i, j, k;
int a[100024];

int main(){
	cin >> n;
	fo(i, n) cin >> a[i];
	bool flag = false;
	int idx1 = 1, idx2 = 1;
	for (i = 1; i < n; i++){
		if(a[i] < a[i - 1]){
			j = i;
			while(j < n and a[j] < a[j - 1]){
				j++;
			}
			if(i == 1){
				idx1 = 1;
				idx2 = j;
				reverse(a, a + j);
			}
			else{
				idx1 = i;
				idx2 = j;
				reverse(a + i -1, a + j);
			}
			break;
		}
	}
	flag = true;
	for (i = 1; i < n; i++){
		if(a[i] < a[i - 1]){
			flag = false;
			break;
		}
	}
	// cout << idx1 << " " << idx2 << "\n";
	if(flag){
		cout << "yes\n";
		cout << idx1 << " " << idx2  << "\n";
	} else{
		cout << "no\n";
	}
}