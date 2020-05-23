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
const int N = 1000;
const int mod = 1e9 + 7;
int n, m;
bool grid[1024][1024];
int find_pairs_right(int row, int col){
	int pairs = 0;
	while(row < N and col < N){
		if(grid[row][col]){
			pairs++;
		}
		row++, col++;
	}
	return pairs;
}
int find_pairs_left(int row, int col){
	int pairs = 0;
	while(row < N and col >= 0){
		if(grid[row][col]){
			pairs++;
		}
		row++, col--;
	}
	return pairs;
}

int main(){
	#ifndef ONLINE_JUDGE	
	OJ
	#endif
	int t, q;
	cin >> n;
	memset(grid, 0, sizeof(grid));
	fo(i, n){
		int x, y;
		cin >> x >> y;
		--x, --y;
		grid[x][y] = 1;
	}
	int ans = 0;
	fo(i, N){
		fo(j, N){
			if(grid[i][j]){
				ans += find_pairs_right(i + 1, j + 1);
				ans += find_pairs_left(i + 1, j - 1);
			}
		}
	}
	print(ans);
}

