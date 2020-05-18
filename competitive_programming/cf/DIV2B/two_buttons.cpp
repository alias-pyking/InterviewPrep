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


int main(){
	#ifndef ONLINE_JUDGE	
	OJ
	#endif
	int t, q;
	int n, m;
	cin >> n >> m;
	array<int, 20001> graph;
	graph.fill(-1);
	queue<int> qu;
	qu.push(n);
	graph[n] = 0;
	while(!qu.empty()){
		int u = qu.front();
		qu.pop();
		if(u == m){
			print(graph[u]);
			return 0;
		}
		int a = 2 * u;
		if(a <= 20000 and graph[a] == -1){ // not visited and check to make sure that a is less that 2 *m
			graph[a] = graph[u] + 1;
			qu.push(a);
		}
		int b = u - 1;
		if(b > 0 and graph[b] == -1) { // not visisted  and check to make sure that b > 0
			graph[b] = graph[u] + 1;
			qu.push(b);
		}
	}
}

