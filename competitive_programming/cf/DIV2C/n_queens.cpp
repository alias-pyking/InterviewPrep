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
bool board[15][15] = {0};
bool is_attacked(int x, int y){
	for (int j = 0; j < n; j++) {
		if(board[x][j])
			return true;
	}
	for (int i = 0; i < n; i++) {
		if(board[i][y])
			return true;
	}
	for (int i = x, j = y; i < n; i++,j++){
		if(j >= n)
			break;
		if(board[i][j])
			return true;
	}
	for (int i = x, j = y; i >= 0; i--,j--){
		if(j < 0)
			break;
		if(board[i][j])
			return true;
	}
	for (int i = x, j = y; i >= 0; i--,j++){
		if(j >= n)
			break;
		if(board[i][j])
			return true;
	}
	for (int i = x, j = y; i < n; i++,j--){
		if(j < 0)
			break;
		if(board[i][j])
			return true;
	}
	return false;
}
bool N_Queens(int x) {
	if(x == 0)
		return true;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			if(is_attacked(i,j))
				continue;
			board[i][j] = 1;
			if(N_Queens(x - 1))
				return true;
			board[i][j] = 0;
		}
	}
	return false;
}
int main(){
	int t, q;
	cin >> n;
	if(N_Queens(n)){
		puts("YES");
		fo(i, n){
			fo(j, n){
				cout << board[i][j] << ' ';
			}
		cout << '\n';
		}
	} else {
		puts("NO");
	}
	return 0;
}

