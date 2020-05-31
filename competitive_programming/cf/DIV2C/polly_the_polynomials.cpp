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

int main(){
	int t, q;
	string line;
	istringstream iss;
	while(getline(cin, line)){
		vl coef;
		iss.str(line);
		ll c;
		while(iss >> c){
			coef.push_back(c);
		}
		iss.clear();
		vl x;
		getline(cin, line);
		iss.str(line);
		ll _x;
		while(iss >> _x){
			x.push_back(_x);
		}
		ll ans = 0;
		n = coef.size();
		m = x.size();
		bool printed = false;
		fo(i, m){
			ans = 0;
			ll _x = x[i];
			int p = n - 1;
			fo(j, n){
				ans += coef[j] * (pow(_x, p));
				p--;
			}
			if(printed)
				cout << ' ';
			else
				printed = true;
			cout << ans;
		}
		cout << '\n';
		iss.clear();
	}
	return 0;
}

