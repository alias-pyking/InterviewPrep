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
ll n, budget;

unordered_map<string, vector<pi>> components;
bool f(int quality){
	int price = 0;
	for(pair<string,vpi> comp: components){
		auto it = lower_bound(comp.second.begin(), comp.second.end(),make_pair(quality,0));
		price += (*it).second;
	}
	return price <= budget;
}
int max_quality(int low, int high){
	while(high - low > 1){
		int mid = (low + high) / 2;
		if(f(mid)){
			low = mid;
		} else {
			high = mid;
		}
	}
	if(f(high)) return high;
	return low;
}
int clean(){
	int mx = INT_MAX;
	for(pair<string,vpi> comp: components){
		string u = comp.first;
		sort(components[u].begin(), components[u].end(),[](pi l, pi r){
			if(l.first == r.first){
				return l.second > r.second;
			}
			return l.first < r.first;
		});
		mx = min(mx, components[u].back().first);
		vpi temp;
		int mn = INT_MAX;
		for (int i = components[u].size() - 1; i >= 0; i--){
			if(mn > components[u][i].second) {
				temp.push_back(components[u][i]);
				mn = components[u][i].second;
			}
		}
		components[u].clear();
		for (int i = temp.size() - 1; i >= 0; i--){
			components[u].push_back(temp[i]);
		}
	}
	return mx;
}
int main(){
	int t, q;
	cin >> t;
	while(t--){
		components.clear();
		cin >> n >> budget;
		fo(i, n){
			string type, name;
			int p, q;
			cin >> type >> name >> p >> q;
			components[type].push_back({q, p});
		}
		cout << max_quality(0, clean()) << '\n';
	}
}

