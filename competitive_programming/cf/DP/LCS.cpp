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
int lcs(string x, string y){
	n = x.length();
	m = y.length();
	int dp[n + 1][m + 1];
	fo(i, n + 1) dp[i][0] = 0;
	fo(j, m + 1) dp[0][j] = 0;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			if(x[i] == y[i]) {
				dp[i][j] = 1 + dp[i - 1][j - 1];
			} else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	return dp[n][m];
}
int main(){
	int t, q;
	string x, y;
	cin >> x >> y;
	x = "_" + x;
	y = "_" + y;
	int res = lcs(x, y);
	cout << res << '\n';
}

