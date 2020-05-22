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
#define REPr(i, a, b) for (int i = a; i >= b; i--)
#define SQ(a) (a)*(a)
#define print(var) cout << var << "\n";
#define print_itrn(seq, n) fo(i, n) print(seq[i])
#define print_itr(seq, n) fo(i, n) cout << seq[i] << " ";
#define OJ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
const int N = 1e5 + 24;
const int mod = 1e9 + 7;
int n, m;

int main(){
	#ifndef ONLINE_JUDGE	
	OJ
	#endif
	int t, q;
	cin >> n;
	int prev = -1, current, next;
	int prev_cnt = 0, current_cnt = 1;
	int max_range = 1;
	cin >> current;
	fo(i, n - 1){
		cin >> next;
		if(next == current){
			current_cnt++;
		} else if(next == prev){
			prev_cnt += current_cnt;
			prev = current;
			current = next;
			current_cnt = 1;
		} else {
			max_range = max(max_range, current_cnt + prev_cnt);
			prev = current;
			prev_cnt = current_cnt;
			current = next;
			current_cnt = 1;
		}
	}
	print(max(max_range, prev_cnt + current_cnt));
}

