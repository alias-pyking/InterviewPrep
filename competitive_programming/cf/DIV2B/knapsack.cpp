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
int ks(int *w, int *v, int c, int i){
	if(i < 0)
		return 0;
	if(c < w[i]){
		return ks(w, v, c, i - 1);
	} else {
		int t1 = v[i] + ks(w, v, c - w[i], i - 1);
		int t2 = ks(w, v, c, i - 1);
		return max(t1, t2);
	}

}
int ksiter(int *w, int *v, int c){
	vector<vi> dp(n + 1, vi(c + 1));
	REP(i, 1, n){
		REP(j, 1, c){
			if(w[i] <= j){
				dp[i][j] = max(v[i] + dp[i - 1][j - w[i]], dp[i-1][j]);
			} else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}
	return dp[n - 1][c];
}
int main(){
	OJ
	int t, q, c;
	cin >> n >> c;
	int v[n];
	int w[n];
	fo(i,n)
		cin >> v[i] >> w[i];
	print(ks(w,v,c,n -1));
	print(ksiter(w, v, c));
}

