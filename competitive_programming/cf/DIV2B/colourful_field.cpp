#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fo(i,n) for (i = 0; i < n; i++)
int n, m, i, j, k, t;
const int C = 1, K = 2, G = 3, W = 4;
int main(){
	cin >> n >> m >> k >> t;
	vector<int> waste_cells;
	while(k--){
		cin >> i >> j;
		i--;
		waste_cells.push_back(i * m + j);
	}
	sort(waste_cells.begin(), waste_cells.end());
	int pos;
	int a, b;
	while(t--){
		cin >> a >> b;
		a--;
		pos = a * m + b;
		int J = 0, flag = false;
		for(int cell: waste_cells){
			if(cell < pos){
				J++;
			} else if(cell == pos){
				flag = true;
			} else
				break;
		}
		pos -= J;
		pos = pos % 3;
		if(flag)
			printf("Waste\n");
		else if ( pos == 1)
			printf("Carrots\n");
		else if (pos == 2)
			printf("Kiwis\n");
		else
			printf("Grapes\n");

	}
	return 0;
}