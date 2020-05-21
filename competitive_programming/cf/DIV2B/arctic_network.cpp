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
	int u, v;
	double w;
	Edge(int u, int v, double w){
		this->u = u;
		this->v = v;
		this->w = w;
	}
	bool operator <(Edge const& other){
		return w < other.w;
	}
};
vi parent, _rank;
void make_set(int u){
	parent[u] = u;
	_rank[u] = u;
}
int find_set(int v){
	if(parent[v] == v)
		return v;
	return parent[v] = find_set(parent[v]);
}
int union_set(int a, int b){
	a = find_set(a);
	b = find_set(b);
	if(a != b){
		if(_rank[a] < _rank[b]){
			swap(a, b);
		}
		parent[b] = a;
		if(_rank[a] == _rank[b])
			_rank[a]++;
		return 1;
	}
	return 0;
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
		int s, p, x[524],y[524];
		cin >> s >> p;
		fo(i, p){
			cin >> x[i] >> y[i];
		}
		parent.resize(p);
		_rank.resize(p);
		fo(i, p) make_set(i);
		vector<Edge> edges;
		vector<Edge> result;
		fo(i, p){
			REP(j, i + 1, p - 1){
				double w = sqrt(SQ(x[i] - x[j]) + SQ(y[i] - y[j]));
				edges.push_back(Edge(i, j, w));
			}
		}
	
		sort(edges.begin(), edges.end());
		double cost = 0;
		int cnt = 0;
		for(auto e: edges){
			cnt += union_set(e.u, e.v);
			if(cnt == p - s){
				printf("%.2lf\n", e.w);
				break;
			}
		}
	}
}

