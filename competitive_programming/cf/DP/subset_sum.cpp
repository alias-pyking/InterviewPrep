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
bool subset_sum(int *a,int n, int t){
	bool dp[n + 1][t + 1];
	fo(i, n) dp[i][0] = true;
	for (int i = 1; i <= t; i++) dp[0][i] = false;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= t; j++){
			if(j < a[i]){
				dp[i][j] = dp[i -1][j];
			} else {
				dp[i][j] = dp[i - 1][j] or dp[i-1][j - a[i]];
			}
		}
	}
	return dp[n - 1][t];
}
int main(){
	int n, t;
	cin >> n >> t;
	int a[n + 1];
	fo(i, n) cin >> a[i + 1];
	if(subset_sum(a, n, t)){
		cout << "YES";
	} else{
		cout << "NO";
	}
	return 0;
}

