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
int n, m, k;

int main(){
	#ifndef ONLINE_JUDGE	
	OJ
	#endif
	int t, q;
	cin >> n >> k;
	t = k;
	char output[n][n];
	fo(i, n){
		fo(j, n){
			output[i][j] = 'S';
		}
	}
	REP(j, 0, n - 1){
		if(j%2 == 0){
			for (int i = 0; i < n and k; i+= 2){
				output[i][j] = 'L';
				k--;
			}
		} else {
			for(int i = 1; i < n and k; i+= 2){
				output[i][j] = 'L';
				k--;
			}
		}
	}
	if(k == 0){
		printf("YES\n");
		fo(i, n)
		{
			fo(j, n){
				printf("%c", output[i][j]);
			}
			printf("\n");
		}
	} else {
		printf("NO\n");
	}
}

