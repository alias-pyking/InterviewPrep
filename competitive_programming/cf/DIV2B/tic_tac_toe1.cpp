#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fo(i,n) for (i = 0; i < n; i++)

int ar[100024];

bool is_win(string config){
	bool rows = (config[0] != '.' and config[0] == config[1] and config[1] == config[2]) or
				(config[3] != '.' and config[3] == config[4] and config[4] == config[5]) or
				(config[6] != '.' and config[6] == config[7] and config[7] == config[8]);
	bool columns = (config[0] != '.' and config[0] == config[3] and config[3] == config[6]) or
				   (config[1] != '.' and config[1] == config[4] and config[4] == config[7]) or
				   (config[2] != '.' and config[2] == config[5] and config[5] == config[8]);
	bool diagonals = (config[0] != '.' and config[0] == config[4] and config[4] == config[8]) or
					 (config[2] != '.' and config[2] == config[4] and config[4] == config[6]);
	return rows or columns or diagonals;
}

int main(){
	int n, m, a, b, k, l, r;
	cin >> n;
	while(n--){
		string board = "";
		for (int i = 0; i < 3; i++){
			string row;
			cin >> row;
			board += row;
		}
		string start = ".........";
		queue<pair<string, bool>> q;
		q.push({start, 1});
		string ans = "no";
		while(!q.empty()){
			string cur = q.front().first;
			bool cur_player = q.front().second;
			q.pop();
			if(cur == board){
				ans = "yes";
				break;
			}
			if(is_win(cur))
				continue;
			for (int i = 0; i < 9; i++){
				if(cur[i] == '.'){
					cur[i] = (cur_player ? 'X' : 'O');
					if(cur[i] == board[i]){
						q.push({cur, 1 ^ cur_player});
					}
					cur[i] = '.';
				}
			}
		}
	}
}