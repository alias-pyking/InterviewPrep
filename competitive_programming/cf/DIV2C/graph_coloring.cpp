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
int n, m, max_x = 0;
bool graph[124][124];
bool black[124],ans[124];
// checking to make sure that neighbour don't have the same color or is not black
bool check(int x){
	for (int i = 0; i < n; i++){
		if(black[i] and graph[x][i])
			return 0;
	}
	return 1;
}
void dfs(int i){
	if(i > max_x){
		// means we have found answer to some of the nodes
		max_x = i;
		for (int j = 0; j < n; j++){
			ans[j] = black[j];
		}
	}
	if(i == n)
		return;
	for (int j = 0; j < n; j++){
		if(check(j) and !black[j]){
			black[j] = 1;
			dfs(i + 1);
			black[j] = 0;
		}
	}
	return;
}
int main(){
	int t, q;
	cin >> t;
	while(t--){
		cin >> n >> m;
		memset(graph, 0, sizeof(graph));
		fo(i, m) {
			int u, v;
			cin >> u >> v;
			u--, v--;
			graph[u][v] = 1;
			graph[v][u] = 1;
		}
		memset(black, 0, sizeof(black));
		memset(ans, 0, sizeof(ans));
		max_x = 0;
		dfs(0);
		cout << max_x << '\n';
		bool flag = false;
		for (int i = 0; i < n; i++){
			if(ans[i]){
				if(flag)
					printf(" ");
				printf("%d", i + 1);
				flag = 1;
			}
		}
		puts("");	
	}
	return 0;
}

