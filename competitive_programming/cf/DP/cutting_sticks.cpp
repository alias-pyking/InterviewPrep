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
int l, n;
bool should_cut[1024];
vector<vi> dp(1024, vi(1024));
int min_cost(int st, int en){
	if(dp[st][en] != INT_MAX) return dp[st][en];
	int min_sub_cost = INT_MAX;
	for (int c = st + 1; c < en; c++){
		if(should_cut[c]){
			int len = en - st;
			int cost = len + min_cost(st, c) + min_cost(c, en);
			min_sub_cost = min(cost, min_sub_cost);
		}
	}
	if(min_sub_cost == INT_MAX) min_sub_cost = 0;
	return dp[st][en] = min_sub_cost;
}
int main(){
	while(1){
		memset(should_cut, 0, sizeof(should_cut));
		fo(i, 1024) fill(dp[i].begin(), dp[i].end(), INT_MAX);

		cin >> l;
		if(l == 0) break;

		cin >> n;
		int ci;
		fo(i, n) cin >> ci, should_cut[ci] = true;
		printf("The minimum cutting is %d.\n", min_cost(0, l));
	}
	return 0;
}

