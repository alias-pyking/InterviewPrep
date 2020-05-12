#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pi;
typedef vector<pair<int, int>> vp;
#define maxvec(vec) *max_element(vec.begin(), vec.end())
#define minvec(vec) *min_element(vec.begin(), vec.end())
#define vi(n,name) vector<int> name(n)
#define vl(n, name) vector<ll> name(n)
#define vp(n, name) vector<pi> name(n)
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
int n, m, t, q;
int x, y, k;
int get_moves(int lo, int hi, int xc, int yc){
	while(lo <= hi){
		int mid = lo + (hi - lo) / 2;
		if (x + xc*mid <= n and x + xc*mid >= 1 and y + yc*mid <= m and y + yc*mid >= 1){
			lo = mid + 1;
		} else {
			hi = mid - 1;
		}
	}
	return lo - 1;
}
int main(){
	OJ
	cin >> n >> m;
	cin >> x >> y;
	cin >> k;
	vp(n, vecs);
	fo(i, n) cin >> vecs[i].first >> vecs[i].second;
	int moves = 0;
	fo(i,k){
		t = get_moves(0, max(n, m) + 1, vecs[i].first, vecs[i].second);
		moves += t;
		x = x + vecs[i].first * t;
		y = y + vecs[i].second * t;
	}
	print(moves);
}

