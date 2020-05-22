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
char graph[100][100];
bool vist[100][100];
bool cycle = false;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
void dfs(int x, int y, int fx, int fy, char color){
	if(x < 0 or x >= n or y < 0 or y >= m)
		return;
	if(graph[x][y] != color)
		return;
	if(vist[x][y]){
		cycle = true;
		return;
	}
	vist[x][y] = true;
	for (int i = 0; i < 4; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(nx == fx and ny == fy)
			continue;
		dfs(nx, ny, x, y, color);
	}
}
int main(){
	#ifndef ONLINE_JUDGE	
	OJ
	#endif
	int t, q;
	cin >> n >> m;
	
	fo(i, n){
		fo(j, m){
			cin >> graph[i][j];
		}
	}
	memset(vist, 0, sizeof(vist));
	fo(i, n){
		fo(j, m){
			if(!vist[i][j]){
				cycle = false;
				dfs(i, j, -1, -1, graph[i][j]);
				if(cycle){
					puts("Yes");
					return 0;
				}
			}
		}
	}
	puts("No");
}

