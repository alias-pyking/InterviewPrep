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
ll lcm(ll a, ll b){
    return (a * b) / __gcd(a, b);
}
int main(){
	int t, q;
	ll a, b;
	cin >> a >> b;
	ll c = (ll)a * b;
	ll l = lcm(a, b);
	ll dasha = l / a - 1;
	ll masha = l / b - 1;
	if(dasha < masha)
		dasha++;
	else
		masha++;
	if(masha == dasha) {
		print("Equal");
	} else if(masha > dasha){
		print("Masha");
	} else
	{
		print("Dasha");
	}
	

	return 0;
}

