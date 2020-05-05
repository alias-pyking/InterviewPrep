#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fo(i,n) for (i = 0; i < n; i++)
int n, m, i, j, k;
int a[124];

int main(){
	cin >> n;
	char res[n];
	res[0] = 'R';
	res[1] = 'O';
	res[2] = 'Y';
	res[3] = 'G';
	res[4] = 'B';
	res[5] = 'I';
	res[6] = 'V';
	for (i = 7; i < n; i++){
		res[i] = res[i - 4];
	}
	for (i = 0; i < n; i++){
		cout << res[i];
	}
	cout << "\n";
}