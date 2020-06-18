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
// ((a + b))
// (a*(a*b))
// (a*(a))
int braces(string A) {
	stack<char> stk;
	if(A.find('(') == string::npos) {
		return false;
	}
	int n = A.size();
	for(auto s: A){
		if(s == ')'){
			if(stk.top() == '('){
				return true;
			}
			int cnt = 0;
			while(!stk.empty()){
				if(stk.top() == '('){
					stk.pop();
					break;
				}
				cnt++;
				stk.pop();
			}
			if(cnt == 1) {
				return true;
			}
		}
		else{
			if(!stk.empty() or s =='('){
				stk.push(s);
			}
		}
	}
	return !stk.empty();
}

int main(){
	int t, q;
	cout << braces("(a*(a))");
}

