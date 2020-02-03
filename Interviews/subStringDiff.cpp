#include <iostream>
#include<vector>
#include<math.h>
#include<algorithm>
#include<set>
#include<unordered_map>
#include<map>
#include<unordered_set>
#include<cmath>
#include<cstring>
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
int substringDiff(int k, string P, string Q) {
    int n = P.length();
    int m  = Q.length();
    int dp[n + 1][m + 1];
    clr(dp);
    int result = 0;
    for(int i = 1; i <= n; i++ ) {
            for(int j = 1; j <= m; j++ ) {
                if( P[i - 1] == Q[j - 1] ) {
                    dp[i][j] = dp[ i - 1][j - 1]  +  1;
                    result = max(result, dp[i][j]);
                }else {
                    dp[i][j] = 0;
                }                       
            }
    }
    return result;
}
int main()
{
    int i, k,t;
    string s1;
    string s2;
    cin >> t;
    while (t--)
    {
        cin >> k;
        cin >> s1 >> s2;
        int ans = substringDiff(k, s1, s2);
        cout << ans << "\n";
    }
    
	return 0; 
} 
 