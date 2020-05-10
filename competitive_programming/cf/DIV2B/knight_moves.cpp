#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fo(i,n) for (i = 0; i < n; i++)

int dx[] = {1, 1, -1, -1, 2, 2, -2, -2};
int dy[] = {2, -2, 2, -2, 1, -1, 1, -1};

int dis[10][10];
bool is_valid(int r, int c){
	return (r >= 0 & c >= 0 and r < 8 and c < 8);
}
int bfs(int sr, int sc, int dr, int dc){
	memset(dis, -1, sizeof dis);
	dis[sr][sc] = 0;
	queue<pair<int, int>> q;
	q.push({sr, sc});
	while(!q.empty()){
		int r = q.front().first, c = q.front().second;
		q.pop();
		if(r == dr and c == dc)
			return dis[r][c];
		for (int k = 0; k < 8; k++){
			int nr = r + dx[k];
			int nc = c + dy[k];
			if(!is_valid(nr,nc))
				continue;
			if(dis[nr][nc] == -1){
				dis[nr][nc] = dis[r][c] + 1;
				q.push({nr, nc});
			}
		}
	}
	return -1;
}

int main()
{
	string str1, str2;
	while(cin >> str1 >> str2){
		int mov = bfs(str1[1] - '1', str1[0] - 'a', str2[1] - '1', str2[0] - 'a');
		cout << "To get from " << str1 << " to " << str2 << " takes " << mov << " knight moves.\n";
	}
}