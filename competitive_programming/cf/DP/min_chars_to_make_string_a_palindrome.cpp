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
int min_chars_to_palindrome(string x){
	n = x.length();
	int dp[n + 1][n + 1];
	dp[0][0] = 0;
	for (int i = 1; i <= n; i++) dp[i][i] = dp[i][i-1] = 0;
	for (int t = 1; t <= n; t++){
		for (int i = 0, j = t; j <= n; i++,j++){
			if(x[i] == x[j]){
				dp[i][j] = dp[i + 1][j - 1];
			} else {
				dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]);
			}
		}
	}
}
int main(){
	string x;
	cin >> x;

}

