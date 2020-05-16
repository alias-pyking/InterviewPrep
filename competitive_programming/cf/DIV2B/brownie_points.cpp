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
int stan, ollie;
int main(){
	#ifndef ONLINE_JUDGE	
	OJ
	#endif
	int t, q;
	while(1){
		cin >> n;
		if(n == 0)
			break;

		ll x[n], y[n];
		fo(i, n) cin >> x[i] >> y[i];
		m = n / 2;
		stan = ollie = 0;
		fo(i,n){
			ll dx = x[i] - x[m];
			ll dy = y[i] - y[m];
			if(dx ==  0 or dy == 0)
				continue;
			if(dx * dy > 0)
				stan++;
			else
				ollie++;
		}
		printf("%d %d\n", stan, ollie);
	}
}


