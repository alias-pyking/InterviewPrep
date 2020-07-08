#include <bits/stdc++.h>
using namespace std;

int dfs(vector<int> graph[],int u,bool vist[],int &res){
	vist[u] = true;
	int current_nodes_count = 0;
	for(auto v: graph[u]){
		if(not vist[v]){
			int subtree_nodes_count = dfs(graph, v, vist, res);
			if(subtree_nodes_count % 2 == 0) res++;
			else current_nodes_count += subtree_nodes_count;
		}
	}
	return current_nodes_count + 1;
}
int maximum_edge_removal(int A, vector<vector<int>> &edges){
	vector<int> graph[A + 1];
	for(auto edge: edges) {
		int u = edge[0], v = edge[1];
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	int res = 0;
	bool vist[A + 1] = {0};
	dfs(graph, 1, vist, res);
	return res;
}
int main(){

}

