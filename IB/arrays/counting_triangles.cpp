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

int nTriang(vector<int> &A) {
	sort(A.begin(), A.end());
	int n = A.size();
	int count = 0 % mod;
	for (int i = n - 1; i >= 0; i--){
		int l = 0, r = i - 1;
		while(l < r){
			if(A[l] + A[r] > A[i]){
				count += (r - l);
				count %= mod;
				r--;
			} else{
				l++;
			}
		}
	}
	return count;
}

int main(){
	int t, q;
	vi a;
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	a.push_back(4);
	cout << nTriang(a);
	
}

