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
	int u, v, w;
	bool operator <(Edge const& other){
		return w < other.w;
	}
};

vi parent, _rank;
void make_set(int v){
	parent[v] = v;
	_rank[v] = 0;
}
int find_set(int v){
	if(v == parent[v])
		return v;
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
	#ifndef ONLINE_JUDGE	
	OJ
	#endif
	int t, q;
	cin >> t;
	while(t--){
		cin >> n >> m;
		int cost = 0;
		_rank.clear();
		parent.clear();
		edges.clear();
		result.clear();
		_rank.resize(n);
		parent.resize(n);

		fo(i, n) make_set(i);
		fo(i, m){
			int u, v, w;
			cin >> u >> v >> w;
			--u,--v;
			Edge e;
			e.u = u;
			e.v = v;
			e.w = w;
			edges.push_back(e);
		}
		sort(edges.begin(), edges.end());
		for (Edge e: edges){
			if(find_set(e.u) != find_set(e.v)){
				cost += e.w;
				result.push_back(e);
				union_set(e.u, e.v);
			}
		}
		int second_cost = INT_MAX;
		for(Edge e: result){
			
			fo(i, n) make_set(i);
			int temp_cost = 0, cnt = 0;
			for(Edge _e: edges) {
				if(e.u == _e.u and e.v == _e.v and e.w == _e.w)
					continue;
				if(find_set(_e.u) != find_set(_e.v)){
						cnt++;
						temp_cost += _e.w;
						union_set(_e.u, _e.v);
				}
			}
			if(cnt == n - 1){
				second_cost = min(second_cost, temp_cost);
			}
			
		}	
		printf("%d %d\n", cost, second_cost);
	}
}

