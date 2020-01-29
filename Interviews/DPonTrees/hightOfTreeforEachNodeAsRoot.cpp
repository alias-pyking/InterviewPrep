#include <iostream>
#include<vector>
#include<math.h>
#include<algorithm>
#include<set>
#include<unordered_map>
#include<map>
#include<unordered_set>
#include<hash_map>
#include<cmath>
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
vi adj[N];
int a[N];
int dp[N], in[N],out[N];
void dfs1(int node, int parent) {
    in[node] = 0;
    for(auto child : adj[node]) {
        if(child == parent) continue;
        dfs1(child,node);
        in[node] = max(in[node],1 + in[child]);
    }
}
void dfs2(int node, int parent) {
    int mx1(-1), mx2(-1);
    for(auto child : adj[node]) {
        if(child == parent) continue;
        if(in[child] >= mx1) mx2 = mx1,mx1 = in[child];
        else if(in[child] > mx2) mx2 = in[child];
    }
    for(auto child : adj[node]) {
        if(child == parent) continue;
        int use = mx1;
        if(mx1 == in[child]) {
            use = mx2;
        }
        out[child] = max(1 + out[node],2 + use);
        dfs2(child,node);
    }
}
int main()
{
    int i, n, k, j, u, v;
    cin >> n;
    fo(i, n-1) cin >> u >> u, adj[u].pb(v),adj[v].pb(u);
    Fo(i,1,n +1) cin >> a[i];
    dfs1(1,0);
	return 0; 
} 
 