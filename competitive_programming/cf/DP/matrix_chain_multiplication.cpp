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
int optimal_sequence[100][100] ={};
struct dim{
	int r, c;
	dim(){}
	dim(int r, int c){
		this->r = r;
		this->c = c;
	}
};

void backtrack(int i, int j){
	if(i < j){
		int m = optimal_sequence[i][j];
		printf("(");
		backtrack(i, m);
		printf(" x ");
		backtrack(m + 1, j);
		printf(")");
	}
	if(i == j){
		printf("A%d", i + 1);
	}
}


void matrix_chain_itr(vector<dim> mats){
	int cache[n][n];
	
	fo(i, n) fill(cache[i], cache[i] + n, -1);
	fo(i, n) cache[i][i] = 0;
	for (int l = 2; l <= n; l++){
		for (int i = 0; i <= n - l; i++){
			int j = i + l - 1;
			cache[i][j] = INT_MAX;
			for (int k = i; k < j; k++){
				int cost = cache[i][k] + cache[k + 1][j] + mats[i].r * mats[k].c * mats[j].c;
				if(cost < cache[i][j]){
					cache[i][j] = cost;
					optimal_sequence[i][j] = k;
				}
			}
		}
	}
	backtrack(0, n - 1);
}
int main(){
	int t, q;
	t = 1;
	while(1){
		cin >> n;
		if(!n) break;
		vector<dim> mats;
		memset(dp, -1, sizeof(dp));
		fo(i, n){
			int r, c;
			cin >> r >> c;
			mats.push_back(dim(r, c));
		}
		printf("Case %d: ", t++);
		matrix_chain_itr(mats);
		puts("");
	}
}

