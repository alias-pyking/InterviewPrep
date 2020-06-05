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
ll n, m, d, f, s, t;
ll a[N];
int main(){
	cin >> n >> d;
	fo(i, n) cin >> a[i + 1];
	ll ans = 0, l = 1, r = 3;
	// 1 2 3 4
	while(r <= n){
		// cout << l << ' ' << r << '\n';
		if(l == r)
			r++;
		if(a[r] - a[l] <= d){
			ll k = r - l;
			ans += k * (k - 1) / 2;
			r++;
		} else {
			// ll low = l, high = r;
			// while(low < high){
			// 	ll mid = (low + high) / 2 + 1;
			// 	// print(mid);
			// 	if(a[r] - a[mid] <= d){
			// 		l = mid;
			// 		high = mid - 1;
			// 	} else{
			// 		low = mid + 1;
			// 	}
			// }
			l++;
		}
	}
	cout << ans << '\n';
}

