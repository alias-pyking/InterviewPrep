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
    cin >> n;  
    char prev;
    char curr;
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(i != 0){
            cin >> curr;
            if (curr == prev){
                ans++;
            } else{
                prev = curr;
            }
        } else{
            cin >> prev;
        }
    }
    cout << ans << "\n";
    return 0;
}