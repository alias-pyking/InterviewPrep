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
vi table(N);
bool founded(int k) {
	for (int i = 1; i <= k; i++){
		int t = n / k, j = 2, v = i, sum = table[v];
		while(j <= t){
			v += k;
			sum += table[v];
			j++;
		}
		if(sum == (n/k) and sum >= 3){
			return true;
		}
	}
	return false;
}
int main(){
	int t, q;
	cin >> n;
	fo(i, n) cin >> table[i + 1];
	for (int i = 1; (ll)i * i <= n; i++){
		if(n % i == 0){
			if(founded(i)) {
				puts("YES");
				return 0;
			} else if(founded(n/i)){
				puts("YES");
				return 0;
			}
		}
	}
	puts("NO");
	return 0;
}

