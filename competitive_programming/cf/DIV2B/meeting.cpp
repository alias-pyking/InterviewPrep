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
int n, m, xa, ya, xb, yb;
int arr[N][3];
double distance(int x1, int y1, int x2 ,int y2){
	double a = SQ(x1 - x2);
	double b = SQ(y1 - y2);
	return sqrt(a + b);
}
bool is_inside_radius(int x, int y){
	fo(j,n){
			int x1 = arr[j][0];
			int y1 = arr[j][1];
			int r = arr[j][2];
			if(distance(x, y, x1, y1) <= r){
				return true;
			}
	}
	return false;
}
int main(){
	#ifndef ONLINE_JUDGE	
	OJ
	#endif
	int t, q;
	cin >> xa >> ya >> xb >> yb;
	cin >> n;
	
	fo(i, n) cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
	if(xa > xb){
		swap(xa, xb);
	}
	if(ya > yb){
		swap(ya, yb);
	}
	int res = 0;
	int x, y;
	x = xa;
	REP(i, ya, yb){
		int y = i;
		bool in = is_inside_radius(x, y);
		if(!in){
			res++;
		}

	}
	y = ya;
	REP(i, xa + 1, xb - 1){
		int x = i;
		bool in = is_inside_radius(x, y);
		if(!in){
			res++;
		}
	}
	y = yb;
	REP(i, xa + 1, xb - 1){
		int x = i;
		bool in = is_inside_radius(x, y);
		if(!in){
			res++;
		}
	}
	x = xb;
	REP(i, ya, yb){
		int y = i;
		bool in = is_inside_radius(x, y);
		if(!in){
			res++;
		}
	}
	print(res);
}

