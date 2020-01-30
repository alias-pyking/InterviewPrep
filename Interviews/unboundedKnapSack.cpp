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
int getSum(int *a,int k, int n) {
    if(k <= 0)  return 0;
    if(n == 0) {
        return 0;
    }
    if(k - a[0] < 0) {
        return getSum(a + 1,k,n - 1);
    }
    int first = a[0] + getSum(a,k - a[0],n);
    int second = getSum(a + 1,k,n - 1);
    return max(first,second);
}
int main()
{
    int i, n, k,t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int a[n];
        cin >> k;
        fo(i,n) cin >> a[i];
        int sum = getSum(a,k,n);
        cout << sum << "\n";
    }
    
	return 0; 
} 
 