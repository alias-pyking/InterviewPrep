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
int f[124][124];
int main(){
	#ifndef ONLINE_JUDGE	
	OJ
	#endif
	int t, q;
	cin >> n >> m;
	int a, b, c;
	memset(f, 0, sizeof(f));
	fo(i, m) {
		cin >> a >> b >> c;
		f[a][b] = c;
	}
	Fo(i, n){
		Fo(j, n){
			Fo(k,n){
				if(f[i][j] > 0 and f[j][k] > 0){
					int delta = min(f[i][j], f[j][k]);
					f[i][j] -= delta;
					f[j][k] -= delta;
					f[i][k] += delta;
				}
			}
		}
	}
	int ans = 0;
	Fo(i,n){
		Fo(j, n){
			if(f[i][j] > 0 and f[j][i] >0)
				continue;
			ans += f[i][j];
		}
	}
	print(ans)
}

