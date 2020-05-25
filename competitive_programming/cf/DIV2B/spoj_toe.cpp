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
string grid[3];
bool check_rows(char winner){
	for(int i =0; i < 3; i++){
		if(grid[i][0] == winner and grid[i][1] == winner and grid[i][2] == winner){
			return true;
		}
	}
	return false;
}
bool check_cols(char winner){
	fo(i,3){
		if(grid[0][i] == winner and grid[1][i] == winner and grid[2][i] == winner){
			return true;
		}
	}
	return false;
}
bool check_diagonals(char winner){
	if(grid[0][0] == winner and grid[1][1] == winner and grid[2][2] == winner)
		return true;
	if(grid[0][2] == winner and grid[1][1] == winner and grid[2][0] == winner)
		return true;
	return false;
}
int main(){
	#ifndef ONLINE_JUDGE	
	OJ
	#endif
	int t, q;
	while(1){
		fo(i,3){
			grid[i] = "";
		}
		string str;
		cin >> str;
		if(str == "end")
			break;
		int idx = 0;
		for(int i = 0; i < 9; i+=3){
			grid[idx].push_back(str[i]);
			grid[idx].push_back(str[i + 1]);
			grid[idx].push_back(str[i + 2]);
			idx++;
		}
		// fo(i,3){
		// 	print(grid[i]);
		// }
		int x_cnt = 0, o_cnt = 0;
		fo(i,3){
			fo(j, 3){
				if(grid[i][j] == 'X'){
					x_cnt++;
					continue;
				}
				if(grid[i][j] == 'O'){
					o_cnt++;
				}
			}
		}
		bool possible = true;
		if(o_cnt > x_cnt){
			possible = false;
		}
		if(x_cnt - o_cnt > 1){
			possible = false;
		}
		bool winner_x = check_cols('X') or check_rows('X') or check_diagonals('X');
		if(winner_x){
			if(x_cnt - o_cnt != 1){
				possible = false;
			}
		}
		bool winner_o = check_cols('O') or check_rows('O') or check_diagonals('O');
		if(winner_o){
			if(x_cnt - o_cnt != 0){
				possible = false;
			}
		}
		if(winner_o and winner_x){
			possible = false;
		}
		if(!winner_o and !winner_x){
			bool flag = 0;
			fo(i,3){
				if(flag){
					break;
				}
				fo(j,3){
					if(grid[i][j] == '.'){
						flag = true;
						break;
					}
				}
			}
			if(flag){
				possible = false;
			}
		}
		if(possible){
			print("valid");
		}
		else{
			print("invalid");
		}	
	}
}

