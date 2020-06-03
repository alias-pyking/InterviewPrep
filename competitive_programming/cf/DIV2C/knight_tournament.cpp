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
int main(){
	int t, q;
	cin >> n >> m;
	vl answer(n);
	set<ll> alive;
	fo(i, n) alive.insert(i);
	ll l, r, x;
	fo(i, m){
		cin >> l >> r >> x;
		l--, r--, x--;
		set<ll>::iterator it = alive.lower_bound(l);
		vl to_erase;
		while(it != alive.end()){
			ll cur = *it;
			if(cur > r)
				break;
			if(cur != x){
				to_erase.push_back(cur);
				answer[cur] = x;
			}
			it++;
		}
		for (int j = 0; j < to_erase.size(); j++){
			alive.erase(to_erase[j]);
		}
	}
	answer[x] -= 1;
	for (int i = 0; i < n; i++){
		cout << answer[i] + 1 << ' ';
	}
	puts("");
}

