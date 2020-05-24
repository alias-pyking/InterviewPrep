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
	string st;
	cin >> st;
	vector<char> str;
	str.push_back('_');
	for(char c:st){
		str.push_back(c);
	}
	n = st.length();
	cin >> m;
	int a[m + 1];
	Fo(i, m) cin >> a[i];
	vi sum(n + 24);
	Fo(i, m){
		int l = a[i], r = n - a[i] + 1;
		sum[l]++;
		sum[r]++;
	}
	Fo(i, n / 2){
		if(i!= 0)
			sum[i] += sum[i - 1];
	}
	Fo(i, n/2){
		if(sum[i]%2 != 0){
			
			swap(str[i], str[n - i + 1]);
		}
	}
	Fo(i,n) cout << str[i];
}

