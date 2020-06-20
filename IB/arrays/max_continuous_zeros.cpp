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
struct window
{
	int start, end;
	window(){}
	window(int start, int end){
		this->start = start;
		this->end = end;
	}
};

vi maxone(vi A, int k){
	int n = A.size(), num_zeros = 0;
	int best_window_size = 0;
	int current_window_size = 0;
	window best_window(0,0),current_window(0,0);
	int l = 0, r = 0;
	while( r < n){
		if(A[r] == 1){
			current_window_size++;
			current_window.end = r;
			if(best_window_size < current_window_size){
				best_window.start = current_window.start, best_window.end = current_window.end;
			}
			best_window_size = max(best_window_size, current_window_size);
		} else{
			num_zeros++;
			if(num_zeros > k){
				while (num_zeros > k){
					current_window.start = l;
					if(A[l++] == 0){
						num_zeros--;
					}
				}
				current_window.start = l;
				current_window.end = max(l, r);
				current_window_size = current_window.end - current_window.start + 1;
			} else {
				current_window_size++;
				current_window.end = r;
				if(best_window_size < current_window_size){
					best_window.start = current_window.start, best_window.end = current_window.end;
				}
				best_window_size = max(best_window_size, current_window_size);
			}
		}
		r++;
	}
	vi res;
	for (int i = best_window.start; i <= best_window.end; i++){
		res.push_back(i);
	}
	return res;
}
int main(){
	int t, q;
	cin >> n;
	vi a;
	fo(i, n){
		int c;
		cin >> c;
		a.push_back(c);
	}
	vi res = maxone(a, 4);
	fo(i, res.size()) cout << res[i] << ' ';
}

