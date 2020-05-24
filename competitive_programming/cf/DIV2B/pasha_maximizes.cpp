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
#define OJ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
const int N = 1e5 + 24;
const int mod = 1e9 + 7;
int n, m;

int main(){
	#ifndef ONLINE_JUDGE	
	OJ
	#endif
	int t, q;
	string str;
	int k;
	cin >> str >> k;
	n = str.length();
	vi num;
	fo(i, n) num.push_back(str[i] - '0');
	int i = 0;
	while(i < n){
		int j = i + 1;
		int next_max = -1;
		int pos = -1;
		while(j <= i + k and j < n){
			if(next_max < num[j]){
				next_max = num[j];
				pos = j;
			}
			j++;
		}
		if(next_max > num[i]){
			while(pos > i and k > 0){
				swap(num[pos], num[pos - 1]);
				pos--, k--;
			}
		}
		i++;
	}
	fo(i, n) cout << num[i];

}

