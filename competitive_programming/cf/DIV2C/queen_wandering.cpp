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
char grid[1005][1005];
int dist[1005][1005];
bool done[1005][1005];
int s_x, s_y, t_x, t_y;
int dx[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
bool is_valid(int i, int j) {
	return (i >= 0 and i < n and j >= 0 and j < m);
}
int bfs() {
	queue<pi> q;
	q.push({s_x, s_y});
	dist[s_x][s_y] = 0;
	done[s_x][s_y] = 1;
	while(!q.empty()) {
		pi u = q.front();
		q.pop();
		if(u.first == t_x and u.second == t_y) {
			return dist[t_x][t_y];
		}
		s_x = u.first, s_y = u.second;
		for (int i = 0; i < 8; i++){
			int di = 1, nx, ny;
			while(true){
				nx = s_x + dx[i]*di;
				ny = s_y + dy[i]*di;
				if(!is_valid(nx,ny) or grid[nx][ny] == 'X')
					break;
				if(dist[nx][ny] >= dist[s_x][s_y] + 1) {
					dist[nx][ny] = dist[s_x][s_y] + 1;
					if(!done[nx][ny])
						done[nx][ny] = 1, q.push({nx, ny});
				} else {
					break;
				}
				di++;
			}
		}
	}
	return -1;
}
int main(){
	int t, q;
	scanf("%d\n", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		fo(i, n){
			scanf("%s", grid + i);
			for (int j = 0; j < m; j++){
				if(grid[i][j] == 'S'){
					s_x = i, s_y = j;
				}
				if(grid[i][j] == 'F'){
					t_x = i, t_y = j;
				}
				dist[i][j] = INT_MAX;
				done[i][j] = 0;	
			}
		}
		
		cout << bfs() << '\n';
	}
}

