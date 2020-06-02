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
vi graph[N];
vi cats(N,0);
vector<bool> vist(N, false);
int ans;
void dfs(int u,int parent, int c){
	vist[u] = true;
	if(cats[u])
		c++;
	else
		c = 0;
	if(c > m)
		return;
	int flag = 1;
	for(auto v: graph[u]){
		if(!vist[v] and v != parent){
			flag = 0;
			dfs(v, u, c);
		}
	}
	ans += flag;
}
int main(){
	int t, q;
	cin >> n >> m;
	fo(i, n) cin >> cats[i + 1];
	fo(i, n - 1){
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	ans = 0;
	dfs(1,-1, 0);
	cout << ans << '\n';
}

