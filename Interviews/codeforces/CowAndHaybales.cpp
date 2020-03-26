#include<iostream>
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
const int N = 100;
int a[N];
const int D = 100;
int main()
{
    int i, n, k, t,j,d;
    cin >> t;
    while (t--)
    {
        cin >> n;
        cin >> d;
        fo(i,n) cin >> a[i];
        i = 1;
        bool flag = true;
        while(d--) {
            if(n == 1){
                flag = false;
                cout << a[0] <<"\n";
                break;
            }
            if(d > a[1]) {
                if(a[i+1] > 0){
                    a[i]++;
                    a[i+1]--;
                    if(i > 1 and a[1] > 0){
                        i = 1;
                    }
                } else{
                    i++;
                }
            } else {
                a[0] += d;
                break;
            }
        }

        if(flag) cout << a[0] << "\n";
    }
    

    return 0;

} 
 
