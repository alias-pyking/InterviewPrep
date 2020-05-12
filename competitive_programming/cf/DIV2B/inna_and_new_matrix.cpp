#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pi;

#define maxvec(vec) *max_element(vec.begin(), vec.end())
#define minvec(vec) *min_element(vec.begin(), vec.end())
#define vi(n,name) vector<int> name(n)
#define vl(n, name) vector<ll> name(n)
#define fo(i, n) for (int i = 0; i < n; i++)
#define Fo(i, n) for (int i = 1; i <= n; i++)
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define SQ(a) (a)*(a)
#define print(var) cout << var << "\n"
#define print_itrn(seq, n) fo(i, n) print(seq[i]);
#define print_itr(seq, n) fo(i, n) cout << seq[i] << " ";
#define OJ                            \
	freopen("input.txt", "r", stdin); \
	freopen("output.txt", "w", stdout);
int n, m, t, q;

int solve(string matrix[], int n, int m){
	fo(i,n){
		bool flag = false;
		fo(j,m){
			if (matrix[i][j] == 'S')
				flag = true;
			if(matrix[i][j] == 'G' and flag){
				return -1;
			}
		}
	}
	set<int> distinct_dist;
	fo(i,n){
		int a, b;
		fo(j,m){
			if(matrix[i][j] == 'G'){
				a = j;
			}
			if(matrix[i][j] == 'S'){
				b = j;
			}
		}
		distinct_dist.insert(b - a);
	}
	return distinct_dist.size();
}

int main(){
	OJ
	cin >> n >> m;
	string matrix[n];
	fo(i, n) cin >> matrix[i];
	int moves = solve(matrix, n, m);
	print(moves);
}

