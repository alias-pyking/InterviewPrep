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
int dist[185][185];
void bfs(int i, int j){
	queue<int> qu;
	qu.push(i);
	qu.push(j);
	dist[i][j] = 0;
	while(!qu.empty()){
		int x = qu.front();
		qu.pop();
		int y = qu.front();
		qu.pop();
		int dis = dist[x][y] + 1;
		if(y - 1 >= 0 and dis < dist[x][y-1]){
			qu.push(x);
			qu.push(y - 1);
			dist[x][y - 1] = dis;
		}
		if(y + 1 < m and dis < dist[x][y + 1]){
			qu.push(x);
			qu.push(y + 1);
			dist[x][y + 1] = dis;
		}
		if(x - 1 >= 0 and dis < dist[x-1][y]){
			qu.push(x - 1);
			qu.push(y);
			dist[x - 1][y] = dis;
		}
		if(x + 1 <= n and dis < dist[x + 1][y]){
			qu.push(x + 1);
			qu.push(y);
			dist[x + 1][y] = dis;
		}
	}
}
int main(){
	int t, q;
	cin >> t;
	while(t--){
		vector<pi> vec;
		cin >> n >> m;
		fo(i, n){
			fo(j, m){
				char c;
				cin >> c;
				if(c == '1'){
					dist[i][j] = INT_MIN;
					vec.push_back({i, j});
				} else {
					dist[i][j] = INT_MAX;
				}
			}
		}
		for(auto v: vec){
			bfs(v.first, v.second);
		}
		fo(i, n){
			fo(j, m){
				cout << dist[i][j] << ' ';
			}
			puts("");
		}
	}
}

