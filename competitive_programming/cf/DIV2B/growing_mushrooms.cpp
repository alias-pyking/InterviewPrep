#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pi;
typedef pair<double, double> pd;
typedef vector<pd> vpd;
typedef vector<pair<int, int>> vpi;

#define maxvec(vec) *max_element(vec.begin(), vec.end())
#define minvec(vec) *min_element(vec.begin(), vec.end())
#define vi(n,name) vector<int> name(n)
#define vl(n, name) vector<ll> name(n)
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

bool compare(pd a, pd b){
	if(a.first > b.first){
		return true;
	}
	if(a.first == b.first){
		return a.second < b.second;
	}
	return false;
}

int main(){
	OJ
	int t, q;
	double t1, t2, k, a, b;
	cin >> n >> t1 >> t2 >> k;
	vpd res;
	fo(i,n) {
		cin >> a >> b;
		double l1 = a * t1;
		l1 = l1 - (k * l1) / 100;
		l1 += b * t2;
		double l2 = b * t1;
		l2 = l2 - (k * l2) / 100;
		l2 += a * t2;
		res.push_back({max(l1, l2), i + 1});
	}
	sort(res.begin(), res.end(), compare);
	fo(i, n) printf("%.0f %.2f\n", res[i].second, res[i].first);
}

