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
    int n;
    int p, v, t,s;
    cin >> n;
    int ans = 0;
    for(int i = 0; i < n; i++){
        cin >> p >> v >> t;
        int s = p + v + t;
        if (s >= 2){
            ans++;
        }
    }
    cout << ans << "\n";
}