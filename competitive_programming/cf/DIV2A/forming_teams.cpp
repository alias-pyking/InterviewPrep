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
vector<vector<int>> graph;
vector<int> vis;
enum status
{
	PATH = 0,
	CYCLE = 1
};

status dfs(int cur_node, int parent_node, int &cnt){
	if(vis[cur_node]){
		return CYCLE;
	}
	vis[cur_node] = 1;
	for(auto child_node:graph[cur_node]){
		if(child_node != parent_node){
			cnt++;
			if(dfs(child_node,cur_node,cnt) == CYCLE){
				return CYCLE;
			}
		}
	}
	return PATH;
}

int main(){
	int n, m;
	cin >> n >> m;
	graph = vector<vector<int>>(n);
	vis = vector<int>(n);
	for (int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		u--, v--;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	int to_remove = 0;
	for (int i = 0; i < n; i++){
		if(!vis[i]){
			int cnt = 0;
			status solve = dfs(i, -1, cnt);
			if(solve == CYCLE){
				to_remove += (cnt % 2 == 1);
			}
		}
	}
	if((n - to_remove)%2 == 1){
		to_remove++;
	}
	cout << to_remove << "\n";
	return 0;
}