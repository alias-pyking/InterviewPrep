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
int number_of_painters_required(vector<int> &C, int t){
	int n = C.size(), p = 1, total = 0;
	for (int i = 0; i < n; i++){
		total += C[i];
		if(total > t){
			total = C[i];
			p++;
		}
	}
	return p;
}
ll sum_of_boards(vector<int> &C){
	int n = C.size();
	ll sum = 0;
	for(int a: C){
		sum += (ll)a;
	}
	return sum;
}
int paint(int A, int T, vector<int> &C) {
	const int mod = 10000003;
	ll low = *max_element(C.begin(), C.end());
	ll high = sum_of_boards(C), n = C.size(), ans = -1;
	while(low <= high){
		ll mid = low + (high - low) / 2;
		if(number_of_painters_required(C, mid) <= A){
			ans = mid;
			high = mid - 1;
		} else {
			low = mid + 1;
		}
	}
	return ((T % mod) * (ans % mod)) % mod;
}

int main(){
	int t, q;
	int A, B;
	vector<int> C;
	cin >> A >> B >> n;
	fo(i, n){
		int s;
		cin >> s;
		C.push_back(s);
	}
	cout << paint(A, B, C);
}

