#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fo(i,n) for (i = 0; i < n; i++)
int n, m, i, j, k;
int a[124];

int main(){
	cin >> n;
	vector<char> ans;
	char colors[8] = {'.','R', 'O', 'Y', 'G', 'B', 'I', 'V'};
	int c_idx = 0;
	for (i = 1; i <= n; i++){
		if(i == n){
			if(colors[c_idx%7])
		}
		ans.push_back(colors[c_idx % 7]);
		c_idx++;
	}
	for (i = 0; i < n; i++){
		cout << ans[i];
	}
	cout << "\n";
}