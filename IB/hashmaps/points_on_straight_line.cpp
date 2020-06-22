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
int maxPoints(vector<int> &X, vector<int> &Y) {
	int max_points = 0;
	int n = X.size();
	map<pair<int, int>, int> slope_map;
	for(int  i = 0; i < n; i++){
		int overlap_points = 0, vertical_points = 0, current_max = 0;
		for (int j = i + 1; j < n;j++){
			if(X[i] == X[j] and Y[i] == Y[j]){
				overlap_points++;
			}
			else if(X[i] == X[j]){
				vertical_points++;
			} else {
				int dx = X[j] - X[i];
				int dy = Y[j] - Y[i];
				int g = __gcd(dx, dy);
				dx /= g;
				dy /= g;
				slope_map[{dy, dx}]++;
				current_max = max(current_max, slope_map[{dy,dx}]);
			}
			current_max = max(current_max, vertical_points);
		}
		max_points = max(max_points, current_max + overlap_points + 1);
		slope_map.clear();
	}
	return max_points;
}

int main(){
	int t, q;
	cin >> n;
}

