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
class splitstring : public string {
    vector<string> flds;
public:
    splitstring(string s) : string(s) { };
    vector<string>& split(char delim, int rep=0);
};

// split: receives a char delimiter; returns a vector of strings
// By default ignores repeated delimiters, unless argument rep == 1.
vector<string>& splitstring::split(char delim, int rep) {
    if (!flds.empty()) flds.clear();  // empty vector if necessary
    string work = data();
    string buf = "";
    int i = 0;
    while (i < work.length()) {
        if (work[i] != delim)
            buf += work[i];
        else if (rep == 1) {
            flds.push_back(buf);
            buf = "";
        } else if (buf.length() > 0) {
            flds.push_back(buf);
            buf = "";
        }
        i++;
    }
    if (!buf.empty())
        flds.push_back(buf);
    return flds;
}
string simplifyPath(string A){
	splitstring str(A);
	vector<string> path = str.split('/');
	stack<string> stk;
	for (int i = 0; i < path.size();i++){
		if(path[i] ==".."){
			if(!stk.empty()){
				stk.pop();
			}
		} else if (path[i] !="." and path[i] != ""){
			stk.push(path[i]);
		}
	}
	if(stk.empty()) {
		return "/";
	} else {
		vector<string> result;
		while(!stk.empty()){
			result.push_back(stk.top());
			stk.pop();
		}
		reverse(result.begin(), result.end());
		string res;
		for(auto s: result){
			res.push_back('/');
			res.append(s);
		}
		return res;
	}
}
int main(){
	int t, q;
	cin >> n;
	cout << simplifyPath("/a/b/../c/d/e/../f");
}

