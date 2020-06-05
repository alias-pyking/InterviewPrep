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
const int N = 1e6 + 24;
const int mod = 1e9 + 7;
ll n, m, x[N];
int main(){
	ll t, q;
	cin >> n;
	ll p, Q = 0;
	fo(i, n){
		cin >> p;
		Q ^= p;
	}
	for(ll i = 1; i <= n; i++){
		x[i] = x[i - 1] ^ i;
	}
	for (ll k = 2; k <= n; k++){
		ll t = n / k, r = n % k;
		if(t%2 == 1){
			Q ^= x[k - 1];
		}
		Q ^= x[r];
	}
	cout << Q << '\n';
	return 0;
}

