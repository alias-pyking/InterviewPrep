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
int remove_element(vi &A, int B){
	int n = A.size(), curr_idx = 0;
	for (int i = 0; i < n; i++){
		if(A[i] == B) continue;
		else {
			A[curr_idx++] = A[i];
		}
	}
	return curr_idx;
}
int main(){
	int t, q;
	cin >> n;
	vector<int> A(n);
	fo(i, n) cin >> A[i];
	cin >> m;
	n = remove_element(A, m);
	print_itr(A, n);
}

