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
int n, m, a, b;
ll get_tokens(ll *ar, int x){
	ll max = (ar[x] * a) / b;
	ll l = 0;
	ll r = ar[x] + 1;
	while(l < r){
		ll mid = l + (r - l) / 2;
		ll money = (mid * a) / b;
		if(money == max){
			r = mid;
		} else {
			l = mid + 1;
		}
	}
	return r;
}
int main(){
	#ifndef ONLINE_JUDGE	
	OJ
	#endif
	int t, q;
	cin >> n >> a >> b;
	ll ar[n];
	fo(i, n) cin >> ar[i];
	fo(i, n){
		ll max_tokens_used = get_tokens(ar, i);
		printf("%d ",ar[i] - max_tokens_used);
	}
	puts("");
}

