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
int n, m,total;
int peg[100];
void simulate(int v, int p){
	if(p == n)
		return;
	if(peg[p] == 0){
		peg[p] = v;
		total++;
		return simulate(v + 1, p);
	}
	for (int i = 0; i <= p; i++){
		int root = (int)sqrt(peg[i] + v);
		if(root * root == peg[i] + v){
			peg[i] = v;
			total++;
			return simulate(v + 1, p);
		}
	}
	simulate(v, p + 1);
}
int main(){
	#ifndef ONLINE_JUDGE	
	OJ	
	#endif
	int t, q;
	cin >> t;
	while(t--){
		cin >> n;
		memset(peg, 0, sizeof(peg));
		total = 0;
		simulate(1, 0);
		print(total);
	}
}

