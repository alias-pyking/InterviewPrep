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

unsigned int binary_to_dec(string binary){
	n = binary.length();
	unsigned int base = 1, decimal = 0;
	for (int i = n - 1; i >= 0; i--){
		if(binary[i] == '1'){
			decimal += base;
		}
		base = base * 2;
	}
	return decimal;
}

int main(){
	int t, q;
	unsigned int a, b;
	while(cin >> a >> b){
		int i = 0;
		string res = "";
		while(a or b) {
			unsigned int l_a = a & 1, l_b = b & 1;
			unsigned int  add = l_a ^ l_b;
			if(a)
				a >>= 1;
			if(b)
				b >>= 1;
			res.push_back(add + '0');
		}
		reverse(res.begin(), res.end());
		unsigned int ans = binary_to_dec(res);
		cout << ans << '\n';
	}
}

