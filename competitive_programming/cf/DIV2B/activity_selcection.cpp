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
struct activity{
	int start, finish;
	activity(int start, int finish){
		this->start = start;
		this->finish = finish;
	}
	bool operator<(activity const& other){
		return this->finish < other.finish;
	}
};
int main(){
	#ifndef ONLINE_JUDGE	
	OJ
	#endif
	int t, q;
	cin >> n;
	vector<activity> A;
	fo(i, n){
		int start, finish;
		cin >> start >> finish;
		A.push_back(activity(start, finish));
	}
	sort(A.begin(), A.end());
	activity J = A[0];
	int max_activities = 1;
	for (int i = 1; i < n; i++){
		if(A[i].start >= J.finish){
			J = A[i];
			max_activities++;
		}
	}
	print(max_activities);
}

