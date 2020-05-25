#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pi;
typedef vector<pair<int, int>> vpi;
typedef vector<pair<ll, ll>> vpl;
typedef vector<pair<double, double>> vpd;

#define maxvec(vec) *max_element(vec.begin(), vec.end())
#define minvec(vec) *min_element(vec.begin(), vec.end())
#define fo(i, n) for (int i = 0; i < n; i++)
#define Fo(i, n) for (int i = 1; i <= n; i++)
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define SQ(a) (a)*(a)
#define print(var) cout << var << "\n";
#define print_itrn(seq, n) fo(i, n) print(seq[i])
#define print_itr(seq, n) fo(i, n) cout << seq[i] << " ";
#define OJ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
const int N = 1e5 + 24;
const int mod = 1e9 + 7;
int n, m;
struct Edge{
	string u, v;
	int w;
	Edge(string u, string v, int w){
		this->u = u;
		this->v = v;
		this->w = w;
	}
	bool operator <(Edge const& other){
		return this->w < other.w;
	}
};

unordered_map<string,string> parent;
unordered_map<string, int> _rank;
void make_set(string v){
	parent[v] = v;
	_rank[v] = 0;
}
string find_set(string v){
	if(v == parent[v])
		return v;
	return parent[v] = find_set(parent[v]);
}
void union_set(string a, string b){
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
int main(){
	#ifndef ONLINE_JUDGE	
	OJ
	#endif
	int t, q;
	cin >> t;
	while(t--){
		parent.clear();
		_rank.clear();
		cin >> n >> m;
		vector<Edge> edges;
		fo(i, m){
			string u, v;
			int w;
			cin >> u >> v >> w;
			make_set(u);
			make_set(v);
			edges.push_back(Edge(u,v,w));
		}
		sort(edges.begin(), edges.end());
		int cost = 0;
		for (Edge edge: edges){
			if(find_set(edge.u) != find_set(edge.v)){
				cost += edge.w;
				union_set(edge.u, edge.v);
			}
		}
		print(cost);
	}
}

