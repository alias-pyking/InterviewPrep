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
    int i, n, k, j;
    vector<int> vec(5);
    vec[0] = 1;
    vec[1] = 2;
    vec[2] = 3;
    vec[3] = 4;
    vec[4] = 5;
    vector<int> v;
    auto it = vec.begin();
    v.assign(it, it + 2);
    for(auto itr = v.begin(); itr != v.end(); itr++) {
        cout << *itr << " ";
    }
    cout << "\n";
    return 0;

} 
 