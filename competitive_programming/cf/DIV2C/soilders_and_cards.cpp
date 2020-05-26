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
	int t, q;
	cin >> n;
	int k1, k2;
	cin >> k1;
	list<int> first, second;
	fo(i,k1){
		int x;
		cin >> x;
		first.push_front(x);
	}
	cin >> k2;
	fo(i,k2){
		int x;
		cin >> x;
		second.push_front(x);
	}
	int fights = 0;
	while(!first.empty() and !second.empty() and fights <= 106){
		int f = first.back();
		int s = second.back();
		first.pop_back();
		second.pop_back();
		if(f > s){
			first.push_front(s);
			first.push_front(f);
		} else {
			second.push_front(f);
			second.push_front(s);
		}
		fights++;
	}
	if(fights <= 106){
		cout << fights << ' ' << (first.empty() ? 2 : 1)<<'\n';
	} else {
		print(-1);
	}
}

