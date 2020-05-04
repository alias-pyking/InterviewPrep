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
int n,t;
string grid[100];
int visited[100][100];
void dfs(int i, int j){
	if (i < 0 or i >= n or j < 0 or j >= n){
		return;
	}
	if(visited[i][j] != 0 or grid[i][j] == '.'){
		return;
	}
	visited[i][j] = 1;
	for (int l = -1; l <= 1; l++){
		for (int m = -1; m <= 1; m++){
			dfs(i + l, j + m);
		}
	}
}
int main(){
	cin >> t;
	int t_num = 1;
	while(t_num <= t){
		cin >> n;
		memset(visited, 0, sizeof visited);
		for (int i = 0;i < n; i++){
			cin >> grid[i];
		}
		int cnt = 0;
		for (int i = 0; i < n; i++){
			for (int j = 0;j < n; j++){
				if(grid[i][j] == 'x' and visited[i][j] == 0){
					cnt++;
					dfs(i, j);
				}
			}
		}
		cout <<"Case "<<t_num <<": "<<cnt<< "\n";
		t_num++;
	}
}