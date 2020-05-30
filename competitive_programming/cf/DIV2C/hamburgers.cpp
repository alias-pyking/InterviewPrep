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
ll Cb, Cc, Cs;
ll Nb, Nc, Ns;
ll Pb, Pc, Ps;
ll f(ll x){
	ll t1 = Cb * x - Nb;
	ll t2 = Cc * x - Nc;
	ll t3 = Cs * x - Ns;
	ll money = max((ll)0,t1)*Pb + max((ll)0,t2)*Pc+ max((ll)0,t3)*Ps;
	return money;
}
int main(){

	int t, q;
	map<char, ll> freq;
	string rec;
	cin >> rec;
	for(auto c: rec){
		freq[c]++;
	}
	Cb = freq['B'];
	Cc = freq['C'];
	Cs = freq['S'];
	cin >> Nb >> Ns >> Nc;
	cin >> Pb >> Ps >> Pc;
	ll money;
	cin >> money;
	ll low = 0, high = money + 1000;
	ll ans = 0;
	while(low < high){
		ll x = (low + high + 1) / 2;
		if(f(x) == money){
			ans = x;
			break;
		}
		if(f(x) <= money){
			low = x;
			ans = x;
		} else {
			high = x - 1;
		}
	}
	print(max(ans,low));
}

