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
string countAndSay(int A) {
	vector<string> sequence;
	sequence.push_back("_");
	sequence.push_back("1");
	sequence.push_back("11");
	for (int i = 3; i <= A; i++){
		string current;
		char contagious_char = sequence[i - 1][0];
		int count = 1;
		for (int j = 1; j < sequence[i - 1].size(); j++){
			if(sequence[i - 1][j] != contagious_char){
				current += to_string(count) + contagious_char;
				contagious_char = sequence[i - 1][j];
				count = 1;
				if(j == sequence[i - 1].size() - 1){
					current += to_string(count) + contagious_char;
				}
			} else if (j == sequence[i -1].size() - 1){
				current += to_string(count + 1) + contagious_char;
			} else{
				count++;
			}
		}
		sequence.push_back(current);
	}
	return sequence[A];
}

int main(){
	int t, q;
	cout << countAndSay(10);
}

