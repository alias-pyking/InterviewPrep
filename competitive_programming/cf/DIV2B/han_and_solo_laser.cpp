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
	int x1, y1;
	cin >> n >> x1 >> y1;
	int x[n], y[n];
	fo(i, n) cin >> x[i] >> y[i];
	map<pair<int, int>,bool> shot;
	fo(i, n){
		shot[{x[i], y[i]}] = false;
	}
	int shots = 0;
	fo(i, n){
		int x2 = x[i], y2 = y[i];
		if(!shot[{x2, y2}]) {
			fo(j, n){
				int x3 = x[j], y3 = y[j];
				if(((x2 - x1)*(y3 - y1)) == ((x3 - x1)*(y2 - y1))){
					shot[{x2, y2}] = true;
					shot[{x3, y3}] = true;
				}
			}
			shots++;
		}
	}
	print(shots);
}

