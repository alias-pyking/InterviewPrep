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
ll n, m, x, y;
vl graph[150024];
bool vist[150024];
void dfs(int u, int cnt_v, int cnt_e){
	vist[u] = 1;
	cnt_v++;
	cnt_e += graph[u].size();
	for(auto v: graph[u]) {
		if(!vist[v])
			dfs(v, cnt_v, cnt_e);
	}
}
int main(){
	#ifndef ONLINE_JUDGE	
	OJ
	#endif
	int t, q;
	cin >> n >> m;
	fo(i, m){
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	memset(vist, 0, sizeof(vist));
	for(ll u = 1; u <= n; u++){
		if(!vist[u]){
			int cnt_v = 0, cnt_e = 0;
			dfs(u, cnt_v, cnt_e);
			int c = cnt_v * (cnt_v - 1) / 2;
			// checking if its a clique 
			if (cnt_e != c){
				puts("NO");
				return 0;
			}
		}
	}
	print("YES");
	return 0;
}

