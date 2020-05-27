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
    int k, r;
    cin >> k >> r;
    int shovels = 1;
    int price = k;
    while (price % 10 != 0){
        if(price % 10 == r){
            break;
        }
        price += k;
        shovels++;
    }
    cout << shovels << "\n";
    return 0;
}