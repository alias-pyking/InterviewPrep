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

void find(int x, int y, int a = 0, int b = 1, int  c = 1,int d = 0) {
	int m = a + c, n = b + d;
	if(x == m and n == y)
		return;
	if(x*n < y*m) {
		printf("L");
		find(x, y, a, b, m, n);
	} else {
		printf("R");
		find(x, y, m, n, c, d);
	}
}

int main(){
	#ifndef ONLINE_JUDGE	
	OJ
	#endif
	int t, q;
	int x,y;
	while(1){
		cin >> x >> y;
		if(x == 1 and y == 1)
			return 0;
		find(x, y);
		cout << '\n';
	}
}

