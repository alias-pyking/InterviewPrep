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
int union_set(int a, int b){
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
		return 1;
	}
	return 0;
}
vector<Edge> edges;
vector<Edge> result;
int distance(int x1, int y1, int x2, int y2){
	int ans = SQ(x1- x2) + SQ(y1 - y2);
	return ans;
}
int main(){
	#ifndef ONLINE_JUDGE
	OJ
	#endif
	int t;
	cin >> t;
	while(t--){
		edges.clear();
		result.clear();
		parent.clear();
		_rank.clear();
		int q, x[755], y[755];
		cin >> n;
		_rank.resize(n + 1);
		parent.resize(n + 1);
		REP(i, 0, n) make_set(i);
		Fo(i, n){
			cin >> x[i] >> y[i];
		}
		cin >> m;
		int cnt = 0;
		while(m--){
			int u, v;
			cin >> u >> v;
			cnt += union_set(u, v);
		}
		if(cnt == n - 1){
			puts("No new highways need");
			
		} else {
			Fo(i, n){
				REP(j, i + 1, n){
					if(i != j){
						Edge e;
						e.u = i;
						e.v = j;
						e.w = distance(x[i], y[i], x[j], y[j]);
						edges.push_back(e);
					}
				}
			}
			sort(edges.begin(), edges.end());
			for(Edge e: edges){
				if(find_set(e.u) != find_set(e.v)){
					result.push_back(e);
					union_set(e.u, e.v);
				}
			}
			for(Edge e: result){
				printf("%d %d\n", e.u, e.v);
			}
		}
		if(t)
			puts("");
	}
	return 0;
}

