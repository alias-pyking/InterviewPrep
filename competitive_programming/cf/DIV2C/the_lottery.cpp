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
ll n, m;
array<ll, 20> arr;
ll lcm(ll a, ll b){
    return (a * b) / __gcd(a, b);
}
ll solve(ll i, ll div){
	if(i == m){
		return n / div;
	}
	ll t1 = solve(i + 1, div);
	ll t2 = solve(i + 1, lcm(arr[i], div));
	printf("%lld: %lld %lld %lld %lld\n",i, t1, t2,div,lcm(arr[i],div));
	return t1 - t2;
}
int main(){
	#ifndef ONLINE_JUDGE	
	OJ
	#endif
	int t, q;
	while(cin >> n >> m){
		fo(i, m) cin >> arr[i];
		cout << solve(0, 1) << '\n';
	}
}

