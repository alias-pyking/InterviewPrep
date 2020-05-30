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
struct tower{
	int height, idx;
	tower(){
	}
	tower(int height, int idx){
		this->height = height;
		this->idx = idx;
	}
	bool operator<(const tower& other){
		return this->height < other.height;
	}
	bool operator>(const tower& other){
		return this->height > other.height;
	}
};
int main(){
	int t, q, k;
	cin >> n >> k;
	vector<tower> towers;
	fo(i, n){
		int h;
		cin >> h;
		towers.push_back(tower(h, i));
	}
	int opr = 0;
	vpi ans;
	while(k > 0){
		tower min_t = minvec(towers);
		tower max_t = maxvec(towers);
		if(max_t.height - min_t.height > 0){
			ans.push_back({max_t.idx + 1, min_t.idx + 1});
			opr++;
			towers[min_t.idx].height += 1;
			towers[max_t.idx].height -= 1;
			k--;
		} else {
			break;
		}
	}
	tower min_t = minvec(towers);
	tower max_t = maxvec(towers);
	int min_diff = max_t.height - min_t.height;
	printf("%d %d\n", min_diff, opr);
	for(auto a: ans){
		printf("%d %d\n", a.first, a.second);
	}
	return 0;	
}

