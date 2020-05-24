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
struct request{
	int p, m, number;
	request(int p, int m, int number){
		this->p = p;
		this->m = m;
		this->number = number;
	}
	bool operator<(request const& other){
		return this->m > other.m;
	}
};
struct table{
	int capacity, number;
	table(int capacity, int number){
		this->capacity = capacity;
		this->number = number;
	}
	bool operator<(table const& other){
		return this->capacity < other.capacity;
	}
};
int main(){
	#ifndef ONLINE_JUDGE	
	OJ
	#endif
	int t, q;
	cin >> n;
	vector<request> R;
	fo(i, n){
		int c, p;
		cin >> c >> p;
		R.push_back(request(c, p, i + 1));
	}
	sort(R.begin(), R.end());
	cin >> m;
	vector<table> T;
	fo(i, m){
		cin >> t;
		T.push_back(table(t,i + 1));
	}
	sort(T.begin(), T.end());
	int max_money = 0;
	int max_req = 0;
	vpi result;
	// for(auto t: T){
	// 	cout << t.capacity << ' ' << t.number << '\n';
	// }
	for(auto req: R){
		int peoples = req.p;
		fo(i, m){
			if(T[i].capacity >= peoples){
				max_req++;
				max_money += req.m;
				int rno = req.number;
				int tno = T[i].number;
				// cout << rno << ' ' << tno << '\n';
				// cout << peoples << ' ' << T[i].capacity << '\n';
				result.push_back({rno, tno});
				T[i].capacity = 0;
				break;
			}
		}
	}
	cout << max_req << ' ' << max_money << '\n';
	for(auto r:result){
		cout << r.first << ' ' << r.second << '\n';
	}
}

