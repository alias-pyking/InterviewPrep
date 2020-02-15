#include <iostream>
#include<vector>
#include<math.h>
#include<algorithm>
#include<set>
#include<unordered_map>
#include<map>
#include<unordered_set>
#include<cmath>
#include<stack>
#include<unordered_map>
#include<queue>
#include<map>
#include<cstring>
#include<limits.h>
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
    ll i, n, k, j,t;
    cin >> t;
    while (t--)
    {
        ll x, y, a, b;
        cin >> x >> y >> a >> b;
        ll s = 0;
        ll yx = y - x;
        ll ab = a + b;
        if(yx%ab == 0){
            cout << yx /ab<<"\n";
        } else{
            cout << -1 << "\n";
        }
    }
    
    return 0;

} 
 