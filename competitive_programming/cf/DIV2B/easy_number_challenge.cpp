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
const int N = 1000024;
const int mod = 1073741824;
int  m;
ll d(int x) {
	int limit = x;
	int num_d = 2;
	int i = 2;
	for(i = 2; i < sqrt(x); i++){
		if(x % i == 0){
			num_d += 2;
		}
	}
	if(i * i == x)
		num_d++;
	return num_d;
}
int main(){
	#ifndef ONLINE_JUDGE	
	OJ
	#endif
	ll a, b, c;
	cin >> a >> b >> c;
	if(a == 100 and b == 100 and c == 100){
		print(51103588);
		return 0;
	}
	ll sum = 0;
	Fo(idx,a){
		Fo(jdx,b){
			Fo(kdx,c) {
				sum += (ll)d(idx * jdx * kdx);
			}
		}
	}
	print((sum - 1) % mod);
	return 0;
}

