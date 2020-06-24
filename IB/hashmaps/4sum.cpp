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
vector<vi> four_sum(vi &arr, int target){
	sort(arr.begin(), arr.end());
	int n = arr.size();
	set<vi> result;
	for (int i = 0; i < n; i++){
		for (int j = i + 1; j < n; j++){
			int left = j + 1;
			int right = n - 1;
			int sum = target - arr[i] - arr[j];

			while(left < right){
				int current_sum = arr[left] + arr[right];
				if(current_sum == sum){
					vi temp;
					temp.push_back(arr[i]);
					temp.push_back(arr[j]);
					temp.push_back(arr[left]);
					temp.push_back(arr[right]);
					result.insert(temp);
					left++, right--;
				} else if( current_sum < sum){
					left++;
				} else {
					right--;
				}
			}
		}
	}
	vector<vi> res;
	for(auto v: result){
		res.push_back(v);
	}
	sort(res.begin(), res.end());
	return res;
}
int main(){
	int t, q;
	cin >> n;
}

