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
#define vi(n,name) vector<int> name(n)
#define vl(n, name) vector<ll> name(n)
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

int main(){
	OJ
	int t, q;
	cin >> n >> m;
	int a[n][m];
	fo(i, n){
		fo(j, m)
			cin >> a[i][j];
	}
	int dp[n][m];
	dp[0][0] = a[0][0];
	REP(i, 1, m - 1) dp[0][i] = a[0][i] + dp[0][i - 1];
	REP(i, 1, n - 1) dp[i][0] = a[i][0] + dp[i - 1][0];
	REP(i,1, n - 1){
		REP(j,1,m - 1){
			dp[i][j] = a[i][j] +  min(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	print(dp[n - 1][m - 1]);
}

