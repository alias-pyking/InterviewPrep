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
    int a[5][5];
    int i,j = 0;
    for(i = 0; i < 5; i++){
        for(j = 0; j < 5; j++){
            cin >> a[i][j];
        }
    }
    i = 0, j = 0;
    while (a[i][j] != 1){
        j++;
        if (j >= 5){
            i++;
            j = 0;
        }
    }
    int ans = abs(3 - (i +1)) + abs(3 - (j + 1));
    cout << ans << "\n";

}