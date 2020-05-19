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

int main(){
	#ifndef ONLINE_JUDGE	
	OJ
	#endif
	double a, x, y;
	cin >> a >> x >> y;
	if(x > -a and x < a){
		if(y <= 0){
			print(-1);
			return 0;
		}
		int t = 1;
		if(y < a){
			if(x > -(a/2) and x < (a/2)){
				print(t);
				return 0;
			} else {
				print(-1);
				return 0;
			}
		}
		t = 2;
		int l = 2;
		while(l <= 1e6){
			if(l % 2 == 0){
				if(x > -(a/2) and x < a/2 and y < (l*a) and y > ((l-1)*a)){
					print(t);
					return 0;
				} else if(x > -(a/2) and x < a/2 and y == (l*a)){
					print(-1);
					return 0;
				}
				t++;
			} else {
				if(x == 0 and y < (l*a) and y > (l - 1)*a){
					print(-1);
					return 0;
				}
				if(x > -a and x < 0 and y < (l*a) and y > ((l-1)*a) ){
					print(t);
					return 0;
				} else if(x > -a and x < 0 and y == (l*a)) {
					print(-1);
					return 0;
				}
				 else if(x > 0 and x < a and y < (l*a) and y > ((l-1)*a)){
					print(t + 1);
					return 0;
				} else if(x > 0 and x < a and y == (l*a)){
					print(-1);
					return 0;
				}
				t += 2;
			}
			l++;
		}
		print(-1);
		return 0;
	} else {
		print(-1);
		return 0;
	}

}

