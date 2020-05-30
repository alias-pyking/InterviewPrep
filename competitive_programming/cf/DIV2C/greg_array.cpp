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
int n, m, k;
struct operation{
	int l, r;
	ll d;
};
struct query{
	int x,y;
};
int main(){
	int t, q;
	cin >> n >> m >> k;
	vi a(n);
	vector<operation> oper(m);
	vector<query> quer(k);
	fo(i, n) cin >> a[i];
	fo(i, m) cin >> oper[i].l >> oper[i].r >> oper[i].d;
	fo(i, k) cin >> quer[i].x >> quer[i].y;
	ll prefix_query[m + 1] = {0};
	for (int i = 0; i < k; i++){
		int x = quer[i].x;
		int y = quer[i].y;
		x--, y--;
		prefix_query[x] += 1;
		prefix_query[y + 1] -= 1;
	}
	for (int i = 1; i < m; i++){
		prefix_query[i] += prefix_query[i - 1];
	}
	vl res(n + 1);
	for (int i = 0; i < m; i++){
		int l = oper[i].l;
		int r = oper[i].r;
		ll d = oper[i].d * prefix_query[i];
		l--, r--;
		res[l] += d;
		res[r + 1] -= d;
	}
	for(int i = 1; i < n; i++){
		res[i] += res[i - 1];
	}
	for(int i = 0; i < n; i++){
		res[i] += a[i];
	}
	print_itr(res, n);
}

