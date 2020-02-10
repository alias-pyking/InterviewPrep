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
// O((n^2)
vector<long> riddle(vector<long> arr) {
    // complete this function
    vector<long> result;
    int n = arr.size();
    for(int i = 0; i < n; i++) {
        vector<long> vMin;
        auto it = arr.begin();
        for( ; it != arr.end() - i; it++) {
            vector<long> vec;
            vec.assign(it, it + i + 1);
            vMin.push_back(*min_element(vec.begin(),vec.end()));
        }
        result.push_back(*max_element(vMin.begin(),vMin.end()));
    }
    return result;

}
int main()
{
    int i, n, k, j;
   
    return 0;

} 
 