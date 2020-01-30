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
const int N = 1e5+4;
int maxXor = 8191;
int primeXor(int *a,int n) {
    int f[2][maxXor + 2];
    // It's fucking hard m not able to solve it 

}

int main()
{
    int i, n,q;
    cin >> q;
    while (q--)
    {
        cin >> n;
        int a[n];
        fo(i,n) cin >> a[i];
        int ans = primeXor(a,n);
        cout << ans << "\n";
    }
    
	return 0; 
} 
 