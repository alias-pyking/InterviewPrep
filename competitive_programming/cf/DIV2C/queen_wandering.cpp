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
bool vist[1001][1001];
int dx[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
struct node{
	int x, y, w;
	node(int x, int y, int w){
		this->x = x;
		this->y = y;
		this->w = w;
	}
};
int bfs(string board[], int i, int j, int tx, int ty) {
	queue<node> qu;
	qu.push(node(i, j, 0));
	vist[i][j] = true;
	for (int row = 0; row < n; row++){
		for (int col = 0; col < m; col++){
			if(board[row][col] == 'X'){
				vist[row][col] = true;
			}
		}
	}
	node dest(tx, ty, 0);
	while(!qu.empty()) {
		node p = qu.front();
		qu.pop();
		if(p.x == dest.x and p.y == dest.y){
			return p.w -1;
		}	
		for (int k = 0; k < 8; k++){
			int nx = p.x + dx[k];
			int ny = p.y + dy[k];
			if(nx < 0 or nx >= n or ny < 0 or ny >= m)
				continue;
			if(!vist[nx][ny]){
				qu.push(node(nx, ny, 1 + p.w));
				vist[nx][ny] = true;
			}
		}
	}
	return -1;
}
int main(){
	int t, q;
	scanf("%d\n", &t);
	while(t--){
		scanf("%d %d\n", &n, &m);
		int x , y, tx, ty;
		string board[1001];
		memset(vist, false, sizeof(vist));
		fo(i, n){
			cin >> board[i];
		}
		for(int i =0; i < n; i++){
			for (int j = 0; j < m; j++){
				if(board[i][j] == 'S'){
					x = i;
					y = j;
				}
				if(board[i][j] == 'F'){
					tx = i;
					ty = j;
				}
				// cout << board[i][j] << ' ';
			}
			// cout << '\n';
		}
		int ans = bfs(board,x, y, tx, ty);
		printf("%d\n", ans);
	}
}

