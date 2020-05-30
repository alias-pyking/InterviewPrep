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
#define print_itr(seq, n) fo(i, n) cout << seq[i];
#define OJ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
const int N = 1e5 + 24;
const int mod = 1e9 + 7;
int n, m;
struct match{
	ll score;
	int pos, idx;
	match(ll score, int pos, int idx) {
		this->score = score;
		this->pos = pos;
		this->idx = idx;
	}
	bool operator<(const match& other){
		return this->score < other.score;
	}
};
int main(){
	int t, q;
	cin >> n;
	vector<match> m1, m2;
	fo(i, n){
		ll s1, s2;
		cin >> s1 >> s2;
		m1.push_back(match(s1, 1, i));
		m2.push_back(match(s2, 2, i));
	}
	vector<match> m;
	fo(i,n) m.push_back(m1[i]);
	fo(i, n) m.push_back(m2[i]);
	sort(m.begin(), m.end());
	vi res1(n);
	vi res2(n);
	int i = 0;
	while(i < n){
		if(m[i].pos == 1) {
			res1[m[i].idx] = 1;
		}
		else {
			res2[m[i].idx] = 1;
		}
		i++;
	}
	i = 0;
	while(i < n/2) {
		res1[m1[i].idx] = 1;
		res2[m2[i].idx] = 1;
		i++;
	}
	print_itr(res1, n);
	puts("");
	print_itr(res2, n);
	return 0;
}

