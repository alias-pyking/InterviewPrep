#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
using namespace std;
#define ll long long

int main(){
    int a1, a2, a3, a4,ans = 0;
    cin >> a1 >> a2 >> a3 >> a4;
    string s;
    cin >> s;
    int n = s.length();
    for(int i = 0; i < n; i++) {
        switch(s[i]){
            case '1':
                ans += a1;
                break;
            case '2':
                ans += a2;
                break;
            case '3':
                ans += a3;
                break;
            case '4':
                ans += a4;
                break;
        }
    }
    cout << ans << "\n";
    return 0;
}