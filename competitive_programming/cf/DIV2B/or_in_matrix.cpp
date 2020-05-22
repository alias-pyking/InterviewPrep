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
int mat[124][124];
int A[124][124];
bool check_col(int col, int b){
	for (int row = 0; row < n; row++){
		if(A[row][col] == b){
			return true;
		}
	}
	return false;
}
bool check_row(int row, int b){
	for (int col = 0; col < m; col++){
		if(A[row][col] == b){
			return true;
		}
	}
	return false;
}
int main(){
	#ifndef ONLINE_JUDGE	
	OJ
	#endif
	int t, q;
	cin >> n >> m;
	
	fo(i, n){
		fo(j, m){
			cin >> mat[i][j];
			A[i][j] = 1;
		}
	}
	fo(i, n){
		fo(j, m){
			if(mat[i][j] == 0){
				fo(col, m){
					A[i][col] = 0;
				}
				fo(row, n){
					A[row][j] = 0;
				}
			}
		}
	}
	fo(i, n){
		fo(j, m){
			int b = mat[i][j] ^ 1;
			if(b == 1){
				if(check_col(j, b) or check_row(i,b)){
					puts("NO");
					return 0;
				}
			} else{
				if(check_col(j, 1) or check_row(i, 1)){
					continue;
				} else {
					puts("NO");
					return 0;
				}
			}
		}
	}
	puts("YES");
	fo(i, n){
		fo(j, m){
			cout << A[i][j] << ' ';
		}
		cout << '\n';
	}

}

