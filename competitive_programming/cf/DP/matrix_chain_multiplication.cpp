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
int n, m, dp[100][100];
struct dim{
	int r, c;
	dim(){}
	dim(int r, int c){
		this->r = r;
		this->c = c;
	}
};
int matrix_chain(int i, int j, vector<dim> mats){
	if(i == j) return dp[i][j] = 0;
	if(dp[i][j] != -1) return dp[i][j];
	int min_cost = INT_MAX;
	for (int k = i; k < j; k++){
		int cost = matrix_chain(i, k,mats) + matrix_chain(k + 1, j,mats) + mats[i].r * mats[k].c * mats[j].c;
		min_cost = min(min_cost, cost);
	}
	return dp[i][j] =  min_cost;
}
int matrix_chain_itr(vector<dim> mats){
	int cache[n][n];
	fo(i, n) cache[i][i] = 0;
	for (int l = 1; l < n; l++){
		for (int i = 0; i <= n; i++){
			int j = i + l - 1;
			dp[i][j] = INT_MAX;
			for (int k = i; k < j; k++){
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + mats[i].r * mats[k].c * mats[j].c);
			}
		}
	}
}
int main(){
	int t, q;
	cin >> n;
	vector<dim> mats;
	memset(dp, -1, sizeof(dp));
	fo(i, n){
		int r, c;
		cin >> r >> c;
		mats.push_back(dim(r, c));
	}
	cout << matrix_chain(0, n - 1, mats);
}

