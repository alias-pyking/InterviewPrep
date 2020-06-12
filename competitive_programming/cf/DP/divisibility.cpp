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
int n, k, a[N];
int dp[N][124];
bool f(int i, int result_value){
	if(i == n){
		return result_value % k == 0 ? true : false;
	}
	if(dp[i][result_value] != -1) return dp[i][result_value];
	int t1, t2;
	t1 = f(i + 1, ((result_value + a[i])%k + k) % k);
	t2 = f(i + 1, ((result_value - a[i])%k + k) % k);
	return dp[i][result_value] = t1 or t2;
}	
int main(){
	int t, q;
	// OJ
	cin >> t;
	while(t--){
		memset(dp, -1, sizeof(dp));
		cin >> n >> k;
		fo(i, n) cin >> a[i];
		if(f(0,0)){
			cout << "Divisible\n";
		} else {
			cout << "Not divisible\n";
		}
	}
}

