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
int n, m, l, r, x;
int ans;
int cnt;
int a[24];
void number_of_ways(int i, int choosen, int sum, int minc, int maxc){
	if(choosen == cnt){
		if(sum >= l and sum <= r and maxc - minc >= x){
			++ans;
			return;
		}
	}
	if(i >= n)
		return;
	number_of_ways(i + 1, choosen + 1, sum + a[i], min(minc, a[i]), max(maxc, a[i]));
	number_of_ways(i + 1, choosen, sum, minc, maxc);
}
int main(){
	#ifndef ONLINE_JUDGE	
	OJ
	#endif
	int t, q;
	cin >> n >> l >> r >> x;
	fo(i, n) cin >> a[i];
	for (int i = 2; i <= n; ++i){
		cnt = i;
		number_of_ways(0, 0, 0, 1e9, -1);
	}
	print(ans);
}

