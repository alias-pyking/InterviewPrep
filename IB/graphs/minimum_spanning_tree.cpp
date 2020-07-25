#include<bits/stdc++.h>
using namespace std;

struct Edge{
	int u, v, w;
	Edge(){}
	Edge(int u, int v, int w){
		this->u = u;
		this->v = v;
		this->w = w;
	}
	bool operator<(Edge const& other){
		return this->w < other.w;
	}
};
vector<int> parent, _rank;
void make_set(int v){
	parent[v] = v;
	_rank[v] = 0;
}
int find_set(int v){
	if(v == parent[v])	return v;
	return parent[v] = find_set(parent[v]);
}
void union_set(int a, int b){
	a = find_set(a);
	b = find_set(b);
	if(a != b){
		if(_rank[a] < _rank[b]){
			swap(a, b);
		}
		parent[b] = a;
		if(_rank[a] == _rank[b]){
			_rank[a]++;
		}
	}
}
vector<Edge> edges;
vector<Edge> result;
int main(){
	int n, m, cost = 0;
	cin >> n >> m;
	_rank.resize(n);
	parent.resize(n);
	for (int i = 1; i <= n; i++) make_set(i);
	for (int i = 0; i < m; i++){
		int u, v, w;
		cin >> u >> v >> w;
		edges.push_back(Edge(u, v, w));
	}
	sort(edges.begin(), edges.end());
	for(auto e: edges){
		if(find_set(e.u) != find_set(e.v)){
			cost += e.w;
			result.push_back(e);
			union_set(e.u, e.v);
		}
	}
	cout << cost << '\n';
}

