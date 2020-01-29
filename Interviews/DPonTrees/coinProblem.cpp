#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;i<n;i++)
#define ll long long
#define pii pair<int,int>
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define clr(x) memset(x, 0, sizeof(x))
#define init(x, a) memset(x, a, sizeof(x))
 
const int mod = 1000000007;
int mpow(int base, int exp); 
const int N = 1e5+4;
vi adj[N]
int dp1[N],dp2[N];
void dfs(int node, int parent) {
    int sum1 = 0;
    int sum2 = 0;
    for(auto child: adj[node]) {
        if(child == parent) continue;
        dfs(child,node);
        sum1 += dp2[child];
        sum2 += max(dp1[child],dp2[child])
    }
}
int main()
{
    int n, i, u, v;
    cin >> n;
    fo(i,n) cin >> u >> v, adj[u].pb(v), adj[v].pb(u);
    dfs(1,0);
	return 0; 
} 
 