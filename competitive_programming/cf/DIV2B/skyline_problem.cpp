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
const int N = 1e4 + 24;
const int mod = 1e9 + 7;
int n, m;
vi H(N);
int main(){
	#ifndef ONLINE_JUDGE	
	OJ
	#endif
	int t, q;
	int l, h, r;
	int max_r = 0;
	int min_l = 1e9;
	while(cin >> l >> h >> r){
		REP(i, l, r - 1){
			H[i] = max(H[i], h);
		}
		min_l = min(min_l, l);
		max_r = max(max_r, r);
	}
	int i = min_l;
	int current_height = 0;
	bool not_first = false;
	for (int pos = 0; pos != 10000; pos++){
		if(H[pos] != current_height){
			if(not_first)
				cout << ' ';
			else
				not_first = true;
			cout << pos << ' ' << H[pos];
			current_height = H[pos];
		}
	}
	cout << '\n';
}

