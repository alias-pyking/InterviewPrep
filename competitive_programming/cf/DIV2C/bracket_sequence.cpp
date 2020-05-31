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

int main(){
	int T, q;
	cin >> T;
	for (int t = 1; t <= T; t++){
		cout << "Case " << t << ":\n";
		string s;
		cin >> s;
		n = s.size();
		vector<vi> st(5,{n});
		map<char, int> M = {{')', 4}, {'}', 1}, {']', 2}, {'>', 3}, {'(', -4}, {'{', -1}, {'[', -2}, {'<', -3}};
		vi ans(n + 1, 0);
		for (int i = n - 1; i >= 0; i--){
			int p = M[s[i]];
			if(p > 0){
				st[p].push_back(i);
			} else {
				p = -p;
				bool ok = (st[p].back() < n);
				for (int j = 1; j <= 4 and ok; j++){
					if(st[j].back() < st[p].back()){
						ok = false;
					}
				}
				if(ok){
					int k = st[p].back();
					ans[i] = k - i + 1;
					ans[i] += ans[k + 1];
					st[p].pop_back();
				} else {
					st.assign(5, {n});
				}
			}
		}
		ans.pop_back();
		for(auto i : ans)
			cout << i << '\n';
	}
	return 0;
}

