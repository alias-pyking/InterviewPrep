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
	#ifndef ONLINE_JUDGE	
	OJ
	#endif
	int t, q;
	cin >> n;
	vpi arr(n);
	int value, idx;
	fo(i, n) {
		cin >> value;
		idx = i;
		arr[i].first = value;
		arr[i].second = idx;
	}
	sort(arr.begin(), arr.end());
	// fo(i, n) cout << arr[i].first << ' ' << arr[i].second << '\n';
	int x = 0;
	vpi res;
	int i = 0;
	while(i < n - 1){
	
		if(arr[i].first == arr[i + 1].first){
			int cd = arr[i + 1].second - arr[i].second;
			int j = i + 1;
			bool flag = true;
			// printf("a[%d]: %d a[%d + 1]: %d\n", i, arr[i].first, i, arr[i + 1].first);
			while(arr[i].first == arr[j].first and j < n){
				// printf("here sk1\n");
				// printf("%d - %d %d\n", arr[j].second, arr[j - 1].second, cd);
				if(cd != arr[j].second - arr[j -1].second){
					// printf("here sk2\n");
					flag = false;
				}
				j++;
			}
			
			if(flag){
				res.push_back({arr[i].first, cd});
			}
			i = j;
		} else {
			res.push_back({arr[i].first, 0});
			i++;
		}
	}
	i = n - 1;
	int j = i;
	while(arr[i].first == arr[j].first){
		j--;

	}
	if(j + 1 == i){
		res.push_back({arr[i].first, 0});
	}
	print(res.size());
	fo(some, res.size()) cout << res[some].first <<' ' << res[some].second << '\n';
}

