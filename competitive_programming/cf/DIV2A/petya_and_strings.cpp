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
    string a,b;
    cin >> a >> b;
    for_each(a.begin(), a.end(), [](char & c){
        c = tolower(c);
    });
    for_each(b.begin(), b.end(), [](char & c){
        c = tolower(c);
    });
    if (a < b){
        cout << -1 << "\n";
    } else if ( b < a){
        cout << 1 << "\n";
    } else{
        cout << 0 << "\n";
    }
}