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
// Its a typical lcs problem.
int lcs(char m[], char f[]){
	int x = strlen(m);
	int y = strlen(f);
	int dp[x + 1][y + 1];
	fo(i, x + 1) dp[i][0] = 0;
	fo(j, y + 1) dp[0][j] = 0;
	for(int i = 1; i <= x; i++){
		for (int j = 1; j <= y; j++){
			if(m[i - 1] == f[j - 1]){
				dp[i][j] = 1 + dp[i - 1][j - 1];
			} else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	return dp[x][y];
}
int main(){
	int t, q;
	char m[1024], f[1024];
	t = 1;
	while(gets(m)){
		if(m[0] == '#')
			break;
		gets(f);
		int ans = lcs(m, f);
		printf("Case #%d: you can visit at most %d cities.\n", t++, ans);
	}
}

