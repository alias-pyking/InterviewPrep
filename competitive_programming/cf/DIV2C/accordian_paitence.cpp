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
	int t, q;
	string input;
	while(cin >> input){
		if(input[0] == '#') break;
		vector<stack<string>> cards;
		stack<string> st;
		st.push(input);
		cards.push_back(st);
		for (int i = 1; i < 52; i++){
			stack<string> s;
			string in;
			cin >> in;
			s.push(in);
			cards.push_back(s);
		}
		for (int i = 1; i < cards.size(); i++){
			if(i >= 3 and \
			(cards[i].top()[0] == cards[i - 3].top()[0] or \
			cards[i].top()[1] == cards[i - 3].top()[1])){

				cards[i - 3].push(cards[i].top());
				cards[i].pop();
				if(cards[i].empty()){
					cards.erase(cards.begin() + i, cards.begin() + i + 1);
				}
				i -= 4;
			} else if(i >= 1 and \
					(cards[i].top()[0] == cards[i - 1].top()[0] or \
					cards[i].top()[1] == cards[i - 1].top()[1])) {
				cards[i - 1].push(cards[i].top());
				cards[i].pop();
				if(cards[i].empty()){
					cards.erase(cards.begin() + i, cards.begin() + i + 1);
				}
				i -= 2;
			}
		}
		if(cards.size() == 1){
			printf("1 pile remaining: %d\n", cards[0].size());
		} else {
			printf("%d piles remaining: ",cards.size());
			fo(i, cards.size()){
				if(i){
					cout << ' ';
				}
				cout << cards[i].size();
			}
			puts("");
		}
	}
}

