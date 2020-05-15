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
array<int, 1024> b;
array<int, 1024> w;
int main(){
	#ifndef ONLINE_JUDGE	
	OJ
	#endif
	int t, q, x, y;
	cin >> n >> m >> x >> y;
	b.fill(0);
	w.fill(0);
	fo(i, n) {
		string s;
		cin >> s;
		int l = 1;
		fo(k,m){
			if(s[k]=='.')
				w[l++]++;
			else
				b[l++]++;
		}
	}
	REP(i, 1, m){
		w[i] += w[i - 1];
		b[i] += b[i - 1];
	}

	
	vector<vi> dp(2, vi(m + 1));
	fo(i, x){
		dp[0][i] = w[i];
		dp[1][i] = b[i];
	}
	// 0 is  black 
	// 1 is white
	REP(i, x, m){
		int min_b = INT_MAX;
		int min_w = INT_MAX;
		int k = max(i - y, 0);
		for (int j = i - x; j >= k; j--){
			printf("b[%d] - b[%d]: %d \n", i, j, b[i] - b[j]);
			printf("w[%d] - w[%d]: %d \n",i, j, w[i] - w[j]);
			min_b = min(min_b, dp[1][j] + b[i] - b[j]);
			min_w = min(min_w, dp[0][j] + w[i] - w[j]);
		}
		printf("min_b: %d min_w: %d at i: %d\n", min_b, min_w, i);
		dp[0][i] = min_b;
		dp[1][i] = min_w;
	}
	print(min(dp[0][m], dp[1][m]));
}

