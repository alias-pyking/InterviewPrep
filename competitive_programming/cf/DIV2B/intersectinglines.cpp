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
int n;

int main(){
	#ifndef ONLINE_JUDGE	
	OJ
	#endif
	int t, q;
	cin >> n;
	printf("INTERSECTING LINES OUTPUT\n");
	while(n--){
		double x1, y1, x2, y2, x3, y3, x4, y4;
		cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
		double A1 = (y2 - y1);
		double B1 = (x1 - x2);
		double C1 = x1* y2 - x2 * y1;
		double A2 = (y4 - y3);
		double B2 = (x3 - x4);
		double C2 = x3 * y4 - x4 * y3;
		double det = (A1 * B2) - (A2 * B1);
		if(det == 0){
			if(A1*x3 + B1*y3 - C1 == 0){
				printf("LINE\n");
			} else {
				printf("NONE\n");
			}
			
		} else {
			double x = (B2*C1 - B1*C2) / det;
			double y = (A1 * C2 - A2 * C1) / det;
			printf("POINT %.2f %.2f\n", x, y);
		}
	}
	printf("END OF OUTPUT\n");
}

