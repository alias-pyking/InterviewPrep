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
int solve(vi &A, vi &B, vi &C) {
	int i = A.size() - 1, j = B.size() - 1, k = C.size() - 1;
	int ans = INT_MAX;
	while(i >= 0 and j >= 0 and k >= 0){
		int cur_ans = max(A[i], max(B[j], C[j])) - min(A[i], min(B[j], C[k]));
		ans = min(cur_ans, ans);
		int max_here = max(A[i], max(B[j], C[k]));
		if(A[i] == max_here) i--;
		else if(B[j] == max_here) j--;
		else k--;
	}
	return ans;
}
int main(){
	int t, q;
	cin >> n;
}

