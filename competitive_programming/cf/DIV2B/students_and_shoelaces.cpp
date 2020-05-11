#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fo(i,n) for (i = 0; i < n; i++)

int ar[100024];

vector<int> graph[124];
int main(){
	int n, m, a, b, k, l, r;
	cin >> n >> m;
	int deg[n + 1];
	memset(deg, 0, sizeof deg);
	for (int i = 0; i < m; i++){
		cin >> a >> b;
		deg[a]++;
		deg[b]++;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	int res = 0;
	vector<bool> mark(n + 1);
	deque<int> S;
	while(true){
		fill(mark.begin(), mark.end(), false);
		for (int i = 1; i <= n; i++){
			if(deg[i] == 1){
				mark[i] = true;
				S.push_back(i);
			}
		}
		if(S.empty())
			break;
		res++;
		while(!S.empty()){
			int u = S.front();
			S.pop_front();
			deg[u]--;
			mark[u] = true;
			for(int v: graph[u]){
				if(!mark[v])
					deg[v]--;
			}
		}
	}
	cout << res << "\n";
}
