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
// 1011
// 00 02 03 22 20 23 33 32 30
int main(){
	int t, q;
	cin >> t;
	while(t--){
		int prefix[N] = {0},k;
		string s;
		cin >> n >> k;
		cin >> s;
		for (int i = 1; i <= n; i++){
			prefix[i] = prefix[i - 1];
			if(s[i - 1] == '1')
				prefix[i]++;
		}
		ll ans = 0;
		for (int i = 1; i <= n; i++){
			if(s[i - 1] == '0')
				continue;
			ans += (ll)(prefix[min(n, i + k)] - prefix[max(0, i - k - 1)]);
		}
		ll gc = __gcd(ans, (ll)n * n);
		cout << ans / gc << '/' << (ll)(n * n) / gc << '\n';
	}
}

