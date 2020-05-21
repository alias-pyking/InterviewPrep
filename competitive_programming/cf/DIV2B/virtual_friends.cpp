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
map<string, string> parent;
map<string, int> _rank;
void make_set(string name){
	parent[name] = name;
	_rank[name] = 1;
}
string find_set(string name){
	if(name == parent[name]){
		return name;
	}
	return parent[name] = find_set(parent[name]);
}
void link(string u, string v){
	if(_rank[u] > _rank[v]) {
		swap(u, v);
	}
	parent[u] = v;
	if(_rank[u] <= _rank[v]){
		_rank[v] += _rank[u];
	}
}
int union_set(string u, string v){
	u = find_set(u);
	v = find_set(v);
	if(u != v)
		link(u, v);
	return max(_rank[u], _rank[v]);
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
		cin >> n;
		fo(i, n) {
			int size = 0;
			string u, v;
			cin >> u >> v;
			if(parent.count(u) == 0){
				make_set(u);
			}
			if(parent.count(v) == 0) {
				make_set(v);
			}
			print(union_set(u, v));
		}

	}
}

