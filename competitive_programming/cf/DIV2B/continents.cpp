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
int n, m, sum, ans;
string world_map[21];
char land;
bool vis[21][21];
void dfs(int x, int y){
	if(y < 0)
		y = m - 1;
	if (y >= m)
		y = 0;
	if(x < 0 or x >= n)
		return;
	if(vis[x][y] or world_map[x][y] != land){
		return;
	}
	vis[x][y] = true;
	sum++;
	dfs(x + 1, y);
	dfs(x, y + 1);
	dfs(x - 1, y);
	dfs(x, y - 1);
}
int main(){
	#ifndef ONLINE_JUDGE	
	OJ
	#endif
	int t, q, x, y;
	while(scanf("%d %d", &n, &m) == 2){
		memset(vis, 0, sizeof(vis));
		for (int i = 0; i < n; i++){
			cin >> world_map[i];
		}
		cin >> x >> y;
		land = world_map[x][y];
		sum = 0;
		dfs(x,y);
		ans = 0;
		fo(i, n){
			fo(j, m){
				sum = 0;
				dfs(i, j);
				ans = max(sum, ans);
			}
		}
		print(ans);
	}
}

