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
    string s;
    string t;
    cin >> s;
    cin >> t;
    int i = 0;
    int n = t.length();
    for(int j = 0; j < n; j++){
        if(t[j] == s[i]){
            i++;
        } 
    }
    cout << i + 1 << "\n";
    return 0;
}