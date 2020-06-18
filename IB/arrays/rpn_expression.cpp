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
int evalRPN(vector<string> &expression){
	stack<int> st;
	set<string> operators;
	operators.insert("+");
	operators.insert("-");
	operators.insert("*");
	operators.insert("/");
	for(auto c : expression){
		if(operators.find(c) != operators.end()){
			int b = st.top(); st.pop();
			int a = st.top(); st.pop();
			if(c == "+"){
				st.push(a + b);
			} else if(c == "-"){
				st.push(a - b);
			} else if(c == "*"){
				st.push(a * b);
			} else {
				st.push(a / b);
			}
		} else {
			st.push(stoi(c));
		}
	}
	return st.top();
}
int main(){
	int t, q;
	cin >> n;
}

