#include <iostream>
#include<vector>
#include<math.h>
#include<algorithm>
#include<set>
#include<unordered_map>
#include<map>
#include<unordered_set>
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
int main()
{
    int i,n,t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int B[n];
        fo(i,n) cin >> B[i];
        int A[N];
        int dp[n + 1][2];
        dp[0][1] = 0;
        dp[0][0] = 0;
        for( i = 1; i < n; i++) {
            dp[i][0] = max(dp[i-1][1] + abs(1 - B[i -1]),dp[i-1][0] + abs(1 - 1));
            dp[i][1] = max(dp[i-1][1]+abs(B[i] - B[i -1]),dp[i-1][0]+abs(B[i] - 1));
            
        }
        cout << max(dp[n-1][0],dp[n-1][1]) <<"\n";
    }
    
} 
 