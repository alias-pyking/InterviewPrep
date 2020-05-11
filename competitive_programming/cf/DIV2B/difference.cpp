#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fo(i,n) for (i = 0; i < n; i++)

vector<int> adjList1[524];
vector<int> adjList2[524];
int d[524], vis[524];
int dfs1(int u){
	if(vis[u])
		return 0;
	vis[u] = 1;
	int sum = d[u];
	for(int v: adjList1[u]){
		sum += dfs1(v);
	}
	return sum;
}
int dfs2(int u){
	if(vis[u])
		return 0;
	vis[u] = 1;
	int sum = d[u];
	for(int v: adjList2[u]){
		sum += dfs2(v);
	}
	return sum;
}
int main(){
	int v, e,x, y, q;
	int test_case = 0;
	while(1){
		cin >> v >> e;
		if(v == 0 and e == 0)
			break;
		for (int i = 1; i <= v; i++){
			adjList1[i].clear();
			adjList2[i].clear();
		}
		int total_weight = 0;
		for (int i = 1; i <= v; i++)
			cin >> d[i],total_weight += d[i];

		for (int i = 0; i < e; i++){
			cin >> x >> y;
			adjList1[x].push_back(y);
			adjList2[y].push_back(x);
		}
		cin >> q;
		printf("Case #%d:\n", ++test_case);
		while(q--){
			cin >> x;
			memset(vis, 0, sizeof vis);
			int min_d = dfs1(x);
			memset(vis, 0, sizeof vis);
			int max_d = total_weight - dfs2(x) + d[x];
			printf("%d\n", max_d - min_d);
		}
		puts("");
	}

}