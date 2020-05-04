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
    string prev;
    string cur;
    int gps = 0;
    for(int i = 0 ;i < n; i++){
        if(i != 0){
            cin >> cur;
            if (prev != cur){
                prev = cur;
                gps++;
            }
        } else{
            cin >> cur;
            prev = cur;
            gps++;
        }
    }
    cout << gps << "\n";
}