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
	// OJ
	int t, q;
	cin >> n;
	int a[n];
	fo(i, n) cin >> a[i];
	vector<vi> dp(n, vi(3));
	if(a[0] == 1 or a[0] == 3)
		dp[0][1]++;
	if(a[0] == 2 or a[0] == 3)
		dp[0][2]++;
	REP(i,1,n - 1){
		dp[i][0] = max(dp[i - 1][0], max(dp[i - 1][1], dp[i - 1][2]));
		dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]);
		if(a[i] == 1 or a[i] == 3)
			dp[i][1]++;
		dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]);
		if(a[i] == 2 or a[i] == 3)
			dp[i][2]++;
	}
	print(n - max(dp[n - 1][0], max(dp[n - 1][1], dp[n - 1][2])));

}

