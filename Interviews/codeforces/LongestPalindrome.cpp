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
string s[N];
int main()
{
    int i, n, k, j,m;
    cin >> n >> m;
    set<string> dict;
    fo(i,n) cin >> s[i], dict.insert(s[i]);
    vector<string> left, right;
    string mid;
    for(int i =0; i < n; i++) {
        string str = s[i];
        reverse(str.begin(),str.end());
        if(str == s[i]) {
            mid = str;
        } else if(dict.find(str) != dict.end()) {
            left.pb(s[i]);
            right.pb(str);
            dict.erase(s[i]);
            dict.erase(str);
        }

    }
    string result ="";
    for(auto str: left) {
        result += str;
    }
    result +=mid;
    reverse(right.begin(),right.end());
    for(auto str:right) {
        result+=str;
    }
    cout << result.size() << "\n";
    cout << result << "\n";
    return 0;

} 
 
