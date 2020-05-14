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
// Given N and some allowed numbers write number of ways to write
// N as sum of those numbers , order matters e,g 1 + 1 + 2 != 1 + 2 + 1
int main(){
	OJ
	int t, q;
	cin >> n;
	cin >> t;
	int a[t];
	fo(i, t) cin >> a[i];
	int dp[n + 1] = {0};
	dp[0] = 1;
	fo(i,n + 1){
		for(int x: a){
			if(x <= i){
				dp[i] += dp[i - x];
			}
		}
	}
	print(dp[n]);
}

