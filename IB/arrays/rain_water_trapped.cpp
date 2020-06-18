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
int trap(const vector<int> &A){
	int n = A.size();
	int answer = 0;
	int left[n],right[n];
	left[0] = 0;
	int largest = A[0];
	for(int i = 1; i < n; i++){
		left[i] = largest;
		largest = max(largest, A[i]);
	}
	largest = A[n - 1];
	right[n - 1] = 0;
	for(int i = n - 2; i >= 0; i--){
		right[i] = largest;
		largest = max(largest, A[i]);
	}
	for (int i = 1; i < n - 1; i++) {
		int h = min(left[i], right[i]);
		if(h >= A[i]){
			answer += h - A[i];
		}
	}
	return answer;
}
int main(){
	int t, q;
	cin >> n;
}

