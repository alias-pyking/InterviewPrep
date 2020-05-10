#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fo(i,n) for (i = 0; i < n; i++)
int dx[] = {-1, -1, -1, 1, 1, 1, 0, 0};
int dy[] = {-1, 0, 1, -1, 0, 1, 1, -1};
map<pair<int, int>, bool> allowed;
map<pair<int, int>, bool> vis;
map<pair<int, int>, ll> dist;

int bfs(int sr, int sc, int dr, int dc){
	queue<pair<int,int>> q;
	dist[{sr, sc}] = 0;
	q.push({sr,sc});
	while(!q.empty()){
		int r = q.front().first, c = q.front().second;
		q.pop();
		if ( r == dr and c == dc)
			return dist[{r, c}];
		for (int k = 0; k < 8; k++){
			int nr = r + dx[k];
			int nc = c + dy[k];
			if(allowed[{nr,nc}] and !vis[{nr, nc}]) {
				if(!dist[{nr, nc}] or dist[{nr, nc}] > dist[{r, c}] + 1){
					dist[{nr, nc}] = 1 + dist[{r, c}];
					q.push({nr, nc});
				}
			}
		}
		vis[{r, c}] = true;
	}
	return -1;
}
int main(){
	int x0, y0, x1, y1, n, r, a, b;
	cin >> x0 >> y0 >> x1 >> y1;
	cin >> n;
	while(n--){
		cin >> r >> a >> b;
		for(int i = a; i <= b; i++){
			allowed[{r, i}] = true;
		}
	}
	allowed[{x0, y0}] = true;
	allowed[{x1, y1}] = true;
	int shortest_path = bfs(x0, y0, x1, y1);
	cout << shortest_path << "\n";
}