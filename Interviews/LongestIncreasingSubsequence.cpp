#include<iostream>
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
const int N = 1e5+4;
int LIS(int *a,int n) {
    int dp[n];
    clr(dp);
    dp[0] = 1;
    for(int i=1; i < n; i++) {
        dp[i] = 1;
        for(int j = i - 1; j >= 0; j--) {
            if(a[j] < a[i] && dp[i] < 1 + dp[j]) {
                dp[i] = 1 + dp[j];
            }
        }
    }
    int ans = *max_element(dp,dp + n);
    return ans;
}
int ceilIndex(int *a,int *T,int end,int val){
    int start  = 0;
    int middle;
    int len = end;
    while (start <= end) 
    {
        middle = (start + end) /2;
        if(middle <len && a[T[middle]] < val && val <= a[T[middle + 1]]) {
            return middle + 1;
        } else if(a[T[middle]] < val) {
            start = middle + 1;
        } else
        {
            end  = middle - 1;
        }
        
    }
    return -1;
    
}
int LIS1(int *a,int n) {
    int T[N];
    int R[N];
    int len = 0;
    init(R,-1);
    T[0] = 0;
    for(int i = 1; i < n; i++) {
        if(a[T[0]] > a[i]) T[0] = i;
        else if(a[T[len]] < a[i]){
            T[++len] = i;
        } else
        {
            int index = ceilIndex(a,T,len,a[i]);
            T[index] = i;
        }
    }
    return len + 1;
}
int main()
{
    int i, n;
    cin >> n;
    int a[n];
    fo(i,n) cin >> a[i];
    int lis = LIS(a,n);
    cout << lis << "\n";     
	return 0; 
} 
 