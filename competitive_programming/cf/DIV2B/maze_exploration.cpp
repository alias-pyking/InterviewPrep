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
void dfs(int i, int j,char **maze){ 
	if(maze[i][j] != ' ' or maze[i][j] == 'X' or maze[i][j] == '_' or maze[i][j] == '#')
		return;
	maze[i][j] = '#';
	dfs(i + 1, j,maze);
	dfs(i - 1, j,maze);
	dfs(i, j + 1,maze);
	dfs(i, j - 1,maze);
}
int main(){
	#ifndef ONLINE_JUDGE	
	OJ
	#endif
	int t, q;
	cin >> t;
	while(t--){
		n = 0;
		char **maze = new char*[32];
		fo(i, 32){
			maze[i] = new char[82];
		}
		while(gets(maze[n])){
			if(maze[n][0] == '_')
				break;
			n++;
		}
		for (int i = 0; i <= n; i++){
			m = strlen(maze[i]);
			for (int j = 0; j < m; j++){
				if(maze[i][j] != ' ' and maze[i][j] != 'X' and maze[i][j] != '#' and maze[i][j] != '_'){
					maze[i][j] = ' ';
					dfs(i, j,maze);
				}
			}
		}
		for (int i = 0; i <= n; i++){
			cout << maze[i] << '\n';
		}
	}

}

