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
#define print_itr(seq, n) fo(i, n) cout << seq[i];
#define OJ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
const int N = 1e5 + 24;
const int mod = 1e9 + 7;
int n, m;

int main(){
	#ifndef ONLINE_JUDGE	
	OJ
	#endif
	int t, q;
	string s;
	cin >> s;
	vi num;
	fo(i, s.length()){
		num.push_back(s[i] - '0');
	}
	fo(i, num.size()){
		int j = i - 1;
		while(j >= 0 and num[i] < num[j] and abs(num[i] - num[j]) == 1){
			j--;
		}
		j++;
		swap(num[j], num[i]);
		j = i + 1;
		while(j < n and num[i] > num[j] and abs(num[i] - num[j]) == 1){
			j++;
		}
		j--;
		swap(num[i], num[j]);
	}
	print_itr(num, num.size());

}

