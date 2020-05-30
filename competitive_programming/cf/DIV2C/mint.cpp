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
int lcm(int a, int b){
    return (a * b) / __gcd(a, b);
}
int main(){
	int t, q;
	while(cin >> n >> t){
		if(n == 0 and t == 0){
			break;
		}
		vi coins(n);
		vi tables(t);
		fo(i, n) cin >> coins[i];
		fo(i, t) cin >> tables[i];
		int left[t];
		int right[t];
		memset(left, -1, sizeof(left));
		memset(right, -1, sizeof(right));
		for(int idx = 0; idx < t; idx++){
			int gt_ls_ds = -1;
			int sm_gt_ds = INT_MAX;
			for(int i = 0; i < n; i++){
				for (int j = i + 1; j < n; j++){
					for (int k = j + 1; k < n; k++){
						for (int l = k + 1; l < n; l++){
							int _lcm = lcm(lcm(lcm(coins[i], coins[j]), coins[k]),coins[l]);
							int value = tables[idx];
							int gt = (value / _lcm) * _lcm;
							int sm = gt;
							if(sm < value){
								sm += _lcm;
							}
							gt_ls_ds = max(gt, gt_ls_ds);
							sm_gt_ds = min(sm_gt_ds, sm);
						}
					}
				}
			}
			cout << gt_ls_ds << ' ' << sm_gt_ds << '\n';
		}	
	}
}

