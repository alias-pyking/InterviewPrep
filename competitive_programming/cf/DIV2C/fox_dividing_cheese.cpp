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
int main(){
	#ifndef ONLINE_JUDGE	
	OJ
	#endif
	int t, q;
	int a, b;
	cin >> a >> b;
	int a2 = 0, a3 = 0, a5 = 0;
	int b2 = 0, b3 = 0, b5 = 0;
	while(a and a % 2 == 0){
		a2++;
		a /= 2;
	}
	while(a and a %3 == 0){
		a3++;
		a /= 3;
	}
	while(a and a%5 == 0){
		a5++;
		a /= 5;
	}
	while(b and b % 2 == 0){
		b2++;
		b /= 2;
	}
	while(b and b % 3 == 0){
		b3++;
		b /= 3;
	}
	while(b and b % 5 == 0){
		b5++;
		b /= 5;
	}
	if(a == b){
		cout << abs(a2 - b2) + abs(a3 - b3) + abs(a5 - b5) << '\n';
	} else {
		cout << -1;
	}

}

