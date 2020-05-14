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
string image[1024];
struct color{
	int white = 0;
	int black = 0;
};
pair<int, int> get_pixels(int j){
	int b = 0, w = 0;
	fo(i,n){
		if(image[i][j] == '.')
			w++;
		if(image[i][j] == '#')
			b++;
	}
	return make_pair(w, b);
}
void create_prefix_sum(color prefix[], int j){
	if(image[0][j] == '.'){
		prefix[0].white = 1;
	} else {
		prefix[0].black = 1;
	}
	REP(i,1, n - 1){
		prefix[i].black += prefix[i - 1].black;
		prefix[i].white += prefix[i - 1].white;
		if (image[i][j] == '.'){
			prefix[i].white += 1;
		} else{
			prefix[i].black += 1;
		}
	}
}
int main(){
	OJ
	int t, q, x, y;
	cin >> n >> m >> x >> y;
	string image[n];
	fo(i, n) cin >> image[i];
	int dp[2][m];
	dp[0][0] = 0;
	dp[1][0] = 0;
	fo(j, m){
		pair<int, int> wb = get_pixels(j);
		int w = wb.first;
		int b = wb.second;
		color prefix[n];
		create_prefix_sum(prefix, j);
		int a = min(x, y);
		dp[0][j] = min(dp[1][j - a])
	}
	print(ans);
}

