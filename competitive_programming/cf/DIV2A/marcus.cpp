#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
using namespace std;
#define ll long long
int m,n;
int res[10];
string seq[30];
string path = "@IEHOVA#";
void find_path(int i, int j, int k){
	if(i < 0 or i >= m or j < 0 or j >= n){
		return;
	}
	if(seq[i][j] != path[k]){
		return;
	}
	if(seq[i][j] == '#'){
		for (int i = 0; i < k; i++){
			if(i){
				putchar(' ');
			}
			if(res[i] == 0){
				cout << "forth";
			}
			else if(res[i] == 1){
				cout << "left";
			}
			else{
				cout << "right";
			}			
		}
		cout << "\n";
		return;
	}
	res[k] = 0; // forth
	find_path(i - 1, j, k + 1);
	res[k] = 1; // left
	find_path(i, j - 1, k + 1);
	res[k] = 2; // right
	find_path(i, j + 1, k + 1);
}

int main(){
    int t;
	cin >> t;
	while(t--){
		cin >> m >> n;
		for (int i = 0;i < m; i++)
		{
			cin >> seq[i];
		}
		for (int j = 0; j < n; j++){
			if(seq[m -1][j] == '@'){
				find_path(m - 1, j, 0);
				break;
			}
		}
	}

}