#include <iostream>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<unordered_map>
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
int mpow(int base, int exp); 
const int N = 1e5+4;
int get_min(int *arr) {
    for(int i = 0; i < 26; i++) {
        if(arr[i] > 0) {
            return i;
        }
    }
    return -1;
}
int main()
{
    int i,n;
    string s;
    cin >> s;
    n  = s.length();
    int arr[26];
    clr(arr);
    fo(i,n) arr[s[i] - 'a']++;
    int minS = -1;
    Fo(i,0,26){
        if (arr[i] > 0) {
            minS = i;
            break;
        }
    }
    stack<char> t;
    string u;
    for(i = 0; i < n; i++) {
        t.push(s[i]);
        minS = get_min(arr);
        arr[s[i] - 'a']--;
        while (!t.empty() and (t.top() - 'a') <= minS)
        {
            u.pb(t.top());
            t.pop();
        }
        
    }
    while (!t.empty()){
        u.pb(t.top());
        t.pop();
    }
  
    cout << u << "\n";

    return 0;

} 
 