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
int buy_and_sell_stocks_twice(vector<int> &A){
	int max_total_profit = 0, min_price_so_far = INT_MAX, n = A.size();
	vector<int>first_buy_sell_stocks(n);
	for (int i = 0; i < n; i++){
		max_total_profit = max(max_total_profit, A[i] - min_price_so_far);
		min_price_so_far = min(min_price_so_far, A[i]);
		first_buy_sell_stocks[i] = max_total_profit;
	}
	int max_price_so_far = INT_MIN;
	for (int i = n - 1; i >= 0; i--){
		max_price_so_far = max(max_price_so_far, A[i]);
		max_total_profit = max(max_total_profit, max_price_so_far - A[i] + first_buy_sell_stocks[i - 1]);
	}
	return max_total_profit;
}
int main(){
	int t, q;
}

