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
vector<vi> anagrams(const vector<string> &words){
	vector<vi> result;
	int n = words.size();
	unordered_map<string, vi> hash_map;
	for (int i = 0; i < n; i++){
		string str = words[i];
		sort(str.begin(), str.end());
		if(hash_map.find(str) != hash_map.end()){
			hash_map[str].push_back(i + 1);
		} else {
			vi temp;
			temp.push_back(i + 1);
			hash_map.insert(make_pair(str, temp));
		}
	}
	for (auto u: hash_map){
		result.push_back(u.second);
	}
	return result;
}
int main(){
	int t, q;
	cin >> n;
	vector<string> words;
	for (int i = 0; i < n; i++){
		string str;
		cin >> str;
		words.push_back(str);
	}
	anagrams(words);
}

