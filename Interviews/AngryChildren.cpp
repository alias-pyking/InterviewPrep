#include <iostream>
#include<vector>
#include<math.h>
#include<algorithm>
#include<set>
#include<unordered_map>
#include<map>
#include<unordered_set>
#include<cmath>
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
    int i, n, k;
    cin >> n >> k;
    int a[n];
    fo(i,n) cin >> a[i];
    ll output = 0;
    sort(a,a + n);
    ll prefixSum[n];
    ll ans(INT_MAX);
    ll unfairness = 0;
    prefixSum[0] = a[0];
    for( i =1; i < n; i++) {
        prefixSum[i] = prefixSum[i-1] + a[i];
    }
    for(i = 1; i < n; i++) {
        if(i < k) {
            unfairness = unfairness + (i*a[i]) - prefixSum[i -1];
            ans = unfairness;
        } else
        {
            ll temp = (prefixSum[i - 1] - prefixSum[i-k]) - (k - 1) * a[i-k] + (k - 1) *a[i] - (prefixSum[i - 1] - prefixSum[i -k]);
            if(unfairness - temp > 0) {
                ans = min(ans,unfairness);
                unfairness = unfairness - temp;
            } 
        }
        

    }
    cout << ans << "\n";
    return 0;

} 
 