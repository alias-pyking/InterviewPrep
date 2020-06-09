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
const int N = 5e3 + 24;
const int mod = 1e9 + 7;
int n, m, k;
int main(){
	cin >> n >> m >> k;
	vpi time_r(N);
	vpi time_c(N);
	fo(i, k){
		int q, r, c;
		cin >> q >> r >> c;
		if(q == 1) {
			time_r[r].first = i + 1;
			time_r[r].second = c;
		} else{
			time_c[r].first = i + 1;
			time_c[r].second = c;
		}
	}
	Fo(i, n){
		Fo(j, m){
			pi current = time_r[i].first > time_c[j].first ? time_r[i] : time_c[j];
			cout << current.second << ' ';
		}
		cout << '\n';
	}
}

