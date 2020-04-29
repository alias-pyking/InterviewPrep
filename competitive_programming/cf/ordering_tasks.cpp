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
int n, m, a, u, v;
vector<vector<int>> adjList;
bool visited[1000];
vector<int> result;
void topological_sort(int u){
	visited[u] = true;
	for (auto v:adjList[u]){
		if(!visited[v]){
			topological_sort(v);
		}
	}
	result.push_back(u);
}
int main(){
	while (true)
	{
		cin >> n >> m;
		if(n == 0 and m == 0){
			break;
		}
		result.clear();
		adjList.clear();
		memset(visited, 0, sizeof visited);
		adjList.resize(n + 1);
		for (int i = 1; i <= m; i++){
			cin >> u >> v;
			adjList[u].push_back(v);
		}
		for (int i = 1; i <= n; i++){
			if(!visited[i]){
				topological_sort(i);
			}
		}
		for (int i = n - 1; i >= 0; i--){
			cout << result[i] << " ";
		}
		cout << "\n";
	}
	
}