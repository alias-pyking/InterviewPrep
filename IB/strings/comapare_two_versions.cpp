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
int compareVersion(string A, string B) {
	string a, b;
	int i = 0;
	for ( i = 0; i < A.length(); i++){
		if(A[i] != '0') break;
	}
	while(i < A.length()){ 
		if(i == A.length() - 1 and A[i - 1] == '.' and A[i] == '0')
			break;
		if (A[i] != '.') {
			a.push_back(A[i]);
		}
		i++;
	}
	for (i = 0; i < B.length(); i++){
		if(B[i] != '0') break;
	}
	while(i < B.length()){
		if(i == B.length() - 1 and B[i - 1] == '.' and B[i] == '0')
			break;
		if(B[i] != '.') b.push_back(B[i]);
		i++;
	}
	// cout << a << ' ' << b << '\n';
	if(a > b or a.length() > b.length()) return 1;
	if(b  > a or b.length() > a.length()) return -1;
	return 0;
}

int main(){
	int t, q;
	cout << compareVersion("4444371174137455", "5.168");
}

