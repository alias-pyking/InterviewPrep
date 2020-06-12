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
const int N = 1e4 + 24;
const int mod = 1e9 + 7;
int n, m, k;
vi a(N);
int dp[N][N];
int solve(int i, int j, int m_d){
	if(m_d > k) return m_d;
	if(i > j) return m_d;
	if(a[i] == a[j]) {
		return solve(i + 1, j - 1, m_d);
	} else {
		return min(solve(i, j - 1, m_d + 1), solve(i + 1, j, m_d + 1));
	}
}
int main(){
	int t, q;
	cin >> t;
	for(int tc = 1; tc <= t; tc++){
		cin >> n >> k;
		fo(i, n) cin >> a[i];
		printf("Case %d: ", tc);
		int diff = solve(0, n - 1, 0);
		if(diff == 0) puts("Too easy");
		if(diff > k) puts("Too difficult");

		if(diff > 0 and diff <= k){
			printf("%d\n", diff);
		}
	}
}

