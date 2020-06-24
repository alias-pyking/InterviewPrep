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
// a + b = k;
// b = k - a;
int n, m;
vi two_sum(const vi &arr, int k){
	unordered_map<int, vi> hash_map;
	int n = arr.size();
	vpi candidates;
	for (int i = 0; i < n; i++){
		hash_map[arr[i]].push_back(i);
	}
	for(auto k: hash_map){
		sort(hash_map[k.first].begin(),hash_map[k.first].end());
	}
	for (int i = 0; i < n; i++){
		int a = arr[i];
		int b = k - arr[i];
		if(b == a){
			if(hash_map[b].size() > 1){
				candidates.push_back({hash_map[b][0], hash_map[b][1]});
			}
		} else if(hash_map.find(b) != hash_map.end()){
			for(auto k: hash_map[b]){
				if(k > i){
					candidates.push_back({i, k});
					break;
				}
			}
		}
	}
	if(candidates.size() == 1){
		vi res;
		res.push_back(candidates[0].first);
		res.push_back(candidates[0].second);
		return res;
	}
	int min_index2 = INT_MAX;
	for (int i = 0; i < candidates.size(); i++){
		min_index2 = min(candidates[i].second, min_index2);
	}
	vpi candidates2;
	for (auto c: candidates){
		if(c.second <= min_index2){
			candidates2.push_back(c);
		}
	}
	if(candidates2.size() == 1){
		vi res;
		res.push_back(candidates2[0].first);res.push_back(candidates2[0].second);
		return res;
	}
	vpi candidates3;
	int min_index1 = INT_MAX;
	for(auto c: candidates2){
		min_index1 = min(min_index1, c.first);
	}
	vi res;
	res.push_back(min_index1, min_index2);
	return res;
}
int main(){
	int t, q;
	cin >> n;
}

