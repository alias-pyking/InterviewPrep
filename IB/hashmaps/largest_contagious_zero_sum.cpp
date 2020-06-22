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
// -19,   8,  2, -8,   19, 5, -2, -23 ]
// -19, -11, -9,  -17, 2,  7, 5,  18
vi lszero(vi &seq){
	int n = seq.size();
	unordered_map<int, int> prefix_sum;
	int sum = 0, max_size = 0;
	pair<int, int> req_seq;
	for(int i = 0; i < n; i++){
		sum += seq[i];
		if(max_size == 0 and seq[i] == 0){
			max_size == 1;
			req_seq = {i, i};
		}
		if(sum == 0){
			int temp_size = i + 1;
			if(max_size < temp_size){
				max_size = temp_size;
				req_seq = {0, i};
			}
		}
		if(prefix_sum.find(sum) != prefix_sum.end()){
			int temp = i - prefix_sum[sum];
			if(max_size < temp){
				max_size = temp;
				req_seq = {prefix_sum[sum] + 1, i};
			}
		} else {
			prefix_sum[sum] = i;
		}

	}
	vi res;
	if(max_size == 0){
		return vector<int>();
	}
	for (int i = req_seq.first; i <= req_seq.second; i++){
		res.push_back(seq[i]);
	}
	return res;
}
int main(){
	int t, q;
	cin >> n;
}

