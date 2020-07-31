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
int buy_and_sell(vector<int> A){
	int maxi = A[0], mini = A[0], max_profit_so_far = 0, n = A.size();
	for (int i = 0; i < n; i++){
		if(A[i] < mini){
			mini = A[i], maxi = A[i];
		} else if(A[i] > maxi){
			maxi = A[i];
		}
		max_profit_so_far = max(max_profit_so_far, maxi - mini);
	}
	return max_profit_so_far;
}

int main(){
	int t, q;
	cin >> t;
	vector<int> A(t);
	fo(i, t) cin >> A[i];
	cout << buy_and_sell(A) << '\n';
	return 0;
}

