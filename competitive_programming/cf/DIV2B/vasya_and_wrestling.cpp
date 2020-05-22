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
	vl first, second;
	ll fs = 0, ss = 0;
	int last = -1;
	fo(i, n){
		int move;
		cin >> move;
		if(i == n - 1){
			last = move;
		}
		if(move > 0){
			fs += move;
			first.push_back(move);
		} else {
			ss += (-move);
			second.push_back(-move);
		}
	}
	// printf("%d %d\n", fs, ss);
	// 1 4 5 8
	// 2 3 6 7
	if(fs > ss){
		puts("first");
	} else if(fs < ss){
		puts("second");
	} else{
		if(first == second){
			if(last > 0)
				puts("first");
			else
				puts("second");
		} else {
			vl::iterator f = first.begin();
			vl::iterator s = second.begin();
			while(f != first.end() or s != second.end()){
				if(*f == *s){
					f++;
					s++;
				} else {
					if(*f > *s)
						puts("first");
					else
						puts("second");
					break;
				}
			}

		}
	}

}

