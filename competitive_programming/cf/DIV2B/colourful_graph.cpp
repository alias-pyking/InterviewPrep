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
vpi graph[124];
bool vis[124];
bool dfs(int u,int col, int dst) {
	vis[u] = true;
	if(u == dst)
		return true;
	for(auto c: graph[u]) {
		int v = c.first, color = c.second;
		if(color == col and !vis[v]) {
			if(dfs(v, col, dst))
				return true;
		}
	}
	return false;
}

int main(){
	#ifndef ONLINE_JUDGE	
	OJ
	#endif
	int t, q;
	cin >> n >> m;
	fo(i,m){
		int u, v, c;
		cin >> u >> v >> c;
		graph[u].push_back({v, c});
		graph[v].push_back({u, c});
	}
	cin >> q;
	fo(i,q) {
		int res = 0;
		int u, v;
		cin >> u >> v;
		REP(i, 1, 100){
			memset(vis, 0, sizeof(vis));
			if(dfs(u,i,v))
				res++;
		}
		print(res);
	}
}

