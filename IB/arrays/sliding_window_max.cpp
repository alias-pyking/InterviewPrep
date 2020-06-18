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
vi slidingMaximum(const vi &A, int b){
	deque<int> que;
	int n = A.size();
	for (int i = 0; i < b; i++){
		while(!que.empty() and A[que.back()] <= A[i]){
			que.pop_back();
		}
		que.push_back(i);
	}
	vi res;
	for (int i = b; i < n; i++){
		res.push_back(A[que.front()]);
		while(!que.empty() and que.front() <= i - b){
			que.pop_front();
		}
		while(!que.empty() and A[que.back()] <= A[i]) {
			que.pop_back();
		}
		que.push_back(i);
	}
	res.push_back(A[que.front()]);
	return res;
}

int main(){
	int t, q;
	int a[] = {648, 614, 490, 138, 657, 544, 745, 582, 738, 229, 775, 665, 876, 448, 4, 81, 807, 578, 712, 951, 867, 328, 308, 440, 542, 178, 637, 446, 882, 760, 354, 523, 935, 277, 158, 698, 536, 165, 892, 327, 574, 516, 36, 705, 900, 482, 558, 937, 207, 368};
	vi A;
	for (int i = 0; i < sizeof(a) / sizeof(a[i]); i++){
		A.push_back(a[i]);
	}
	vi res = slidingMaximum(A, 9);
	print_itr(res, res.size());
}

