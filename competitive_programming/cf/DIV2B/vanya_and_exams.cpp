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
ll n, m;
struct exam{
	ll a,b;
	exam(){

	}
	exam(double a, double b){
		this->a = a;
		this->b = b;
	}
	bool operator<(exam const& other){
		return this->b < other.b;
	}
};
int main(){
	#ifndef ONLINE_JUDGE	
	OJ
	#endif
	int t, q;
	ll r, avg;
	cin >> n >> r >> avg;
	vector<exam> A(n);
	fo(i, n){
		cin >> A[i].a >> A[i].b;
	}
	sort(A.begin(), A.end());
	ll min_essays = 0;
	ll sum = 0;
	fo(i, n){
		sum += A[i].a;
	}
	int i = 0;
	while(sum < avg*n and i < n){
		ll add = min(avg * n - sum, r - A[i].a);
		min_essays += A[i].b * add;
		sum += add;
		i++;
	}
	cout << min_essays << '\n';
}

