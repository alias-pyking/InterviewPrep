#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fo(i,n) for (i = 0; i < n; i++)
int n, m, i, j, k;
int main(){
	char pc;
	cin >> n >> m >> pc;
	char office[n][m];
	for (i = 0; i < n; i++){
		for (j = 0; j < m; j++){
			cin >> office[i][j];
		}
	}
	set<char> adj;
	for (i = 0; i < n; i++){
		for (j = 0; j < m; j++){
			if(office[i][j] == pc){
				if(i - 1 >= 0){
					if(office[i- 1][j] != pc and office[i - 1][j] != '.'){
						adj.insert(office[i - 1][j]);
					}
				}
				if(i  + 1 < n){
					if(office[i + 1][j] != pc and office[i + 1][j] !='.'){
						adj.insert(office[i + 1][j]);
					}
				}
				if(j - 1 >= 0){
					if(office[i][j - 1] !=pc and office[i][j - 1] != '.'){
						adj.insert(office[i][j - 1]);
					}
				}
				if (j + 1 < m){
					if(office[i][j + 1] != pc and office[i][j + 1] != '.'){
						adj.insert(office[i][j + 1]);
					}
				}
				
			}
		}
	}
	cout << adj.size() << "\n";
}