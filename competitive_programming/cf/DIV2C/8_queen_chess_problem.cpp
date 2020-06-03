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
int n = 8, m, h;
bool board[15][15] = {0};
int a, b;
bool is_safe(int row, int col){
	for (int j = 0; j < col; j++){
		if(board[row][j])
			return false;
	}
	for (int i = row, j = col; i >= 0 and j >= 0; i--,j--){
		if(board[i][j])
			return false;
	}
	for (int i = row, j = col; j >= 0 and i < n; i++, j--){
		if(board[i][j])
			return false;
	}
	return true;
}
void print_solution(){
	printf("%2d     ",h++);
	for (int c = 0; c < n; c++){
		for (int r = 0; r < n; r++){
			if(board[r][c]){
				printf(" %d",r+1);
			}
		}
	}
	puts("");
}
bool N_Queens(int col) {
	if(col == n and board[a][b] == 1){
		print_solution();
		return true;
	}
	bool res = false;
	for (int row = 0; row < n; row++){
		if(is_safe(row,col)){
			board[row][col] = 1;
			res = N_Queens(col + 1) or res;
			board[row][col] = 0;
		}
	}
	return res;
}
int main(){
	int t, q;
	cin >> t;
	for (int tc = 1; tc <= t; tc++){
		memset(board, 0, sizeof(board));
		cin >> a >> b;
		a--, b--;
		h = 1, n = 8;
		if(tc > 1) puts("");
		printf("SOLN       COLUMN\n");
        printf(" #      1 2 3 4 5 6 7 8\n\n");
		if(!N_Queens(0)){
			cout << "Solution does not exists\n";
		}
		
	}
	return 0;
}

