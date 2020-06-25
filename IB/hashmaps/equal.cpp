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
vi equal(vi &arr){
	int n = arr.size();
	unordered_map<int, vpi> hash_map;
	for (int i = 0; i < n; i++){
		for (int j = i + 1; j < n; j++){
			hash_map[arr[i] + arr[j]].push_back({i, j});
		}
	}
	vi result(4,INT_MAX);
	for(auto p: hash_map){
		if(p.second.size() > 1){
			pi p1 = p.second[0];
			for(auto p2: p.second){
				int a = p1.first, b = p1.second;
				int c = p2.first, d = p2.second;
				if(a < c and a < b and c < d and b != c and b!= d){
					vi temp = {a, b, c, d};
					if(temp < result){
						result = temp;
					}
				}
			}
		}
	}
	return result;
}
int main(){
	int t, q;
	cin >> n;
	string str = "123454";
	str.insert(str.begin() + 5, '(');
	cout << str;
}
