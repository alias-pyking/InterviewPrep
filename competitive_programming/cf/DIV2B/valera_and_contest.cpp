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
int n, k, l, r, sall, sk;
int main(){
	#ifndef ONLINE_JUDGE	
	OJ
	#endif
	int t, q;
	cin >> n >> k >> l >> r >> sall >> sk;
	vi res(n);
	int temp = sk;
	while(sk){
		for (int i = 0; i < k and sk; i++){
			if(sk - 1 > 0){
				res[i] += 1;
				sk--;
			} else {
				res[i] += sk;
				sk = 0;
				break;
			}
		}
	}
	int points_left = sall - temp;
	while(points_left){
		for (int i = k; i < n and points_left; i++){
			if(points_left - 1 > 0){
				res[i] += 1;
				points_left -= 1;
			} else {
				res[i] += points_left;
				points_left = 0;
				break;
			}
		}
	}
	print_itr(res, res.size());
}

