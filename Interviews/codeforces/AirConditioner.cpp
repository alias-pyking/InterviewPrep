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
const int N = 101;
int main()
{
    int i, n, m, q;
    int t[N],l[N],h[N];
    cin >> q;
    int pt =-1;
    while (q--)
    {
        cin >> n >> m;
        fo(i, n) cin >> t[i] >> l[i] >> h[i];
        int mn,mx;
        mn = m;
        mx = m;
        int prev = 0;
        bool flag = true;
        for(i = 0; i < n; i++) {
            mn -= t[i] - prev;
            mx += t[i] - prev;
            if(mn > h[i] or mx < l[i]) {
                flag = false;
                break;
            }
            mn = max(mn, l[i]);
            mx = min(mx, h[i]);
            prev = t[i];
        }
        if(flag) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    

    return 0;

} 
 
