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
int largest_rectangle(vector<int> h){
	stack<int> hist_indexes;
	h.push_back(0);
	int n = h.size(), max_rect = 0;
	for (int i = 1; i < n; i++) {
		while(!hist_indexes.empty() and h[hist_indexes.top()] >= h[i]) {
			int height = h[hist_indexes.top()]; hist_indexes.pop();
			int width;
			if(hist_indexes.empty()){
				width = i;
			} else {
				width = i - hist_indexes.top() - 1;
			}
			max_rect = max(max_rect, height * width);
		}
		hist_indexes.push(i);
	}
	return max_rect;
}
int main(){
	int t, q;
	cin >> n;
}

