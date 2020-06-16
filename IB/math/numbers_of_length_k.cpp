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
vector<int> num_to_vec(int C){
	vector<int> digit;
	while(C != 0){
		digit.push_back(C % 10);
		C /= 10;
	}
	reverse(digit.begin(), digit.end());
	return digit;
}

int solve(vector<int> &A, int B, int C) {
	vector<int> digit = num_to_vec(C);
	int d = A.size();
	if(B > digit.size() or digit.size() == 0) return 0;
	if(B < digit.size()){
		if(A[0] == 0){
			return (d - 1) * pow(d, B - 1);
		} else {
			return pow(d, B);
		}
	} else {
		int dp[B + 1] = {0};
		int lower[11] = {0};
		for(int i = 0; i < d; i++){
			lower[A[i] + 1] = 1;
		}
		for (int i = 1; i <= 11; i++){
			lower[i] += lower[i - 1];
		}
		bool flag = true;
		for (int i = 1; i <= B; i++){
			int d2 = lower[digit[i - 1]];
			dp[i] = dp[i - 1] * d;
			if(i == 1 and A[0] == 0 and B!= 1) d2--;
			if(flag) dp[i] += d2;
			flag = (flag & (lower[digit[i - 1] + 1] == lower[digit[i - 1]] + 1));
		}
		return dp[B];
	}
}

int main(){
	int t, q;
}

