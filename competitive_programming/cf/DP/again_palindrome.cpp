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
string a;
ll dp[65][65];
ll num_of_ways(int i, int j){
	if(i == j) return 1;
	if(i + 1 == j) return 2 + (a[i] == a[j]);
	ll &res = dp[i][j];
	if(res != -1) return res;
	res = 0;
	if(a[i] == a[j]){
		res += 1 + num_of_ways(i + 1, j - 1);
	}
	res += num_of_ways(i + 1, j);
	res += num_of_ways(i, j - 1);
	res -= num_of_ways(i + 1, j - 1); // we are subtracting because we have taken the st
									 // ring from i + 1 to j - 1 twice so we subtract one.

	return res;
}
int main(){
	int t, q;
	cin >> t;
	while(t--){
		a.clear();
		memset(dp, -1, sizeof(dp));
		cin >> a;
		ll ans = num_of_ways(0, a.length() - 1);
		cout << ans << '\n';
	}
	return 0;
}

