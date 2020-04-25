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
    int n,h;
    cin >> n >> h;
    int a[n];
    for(int i =0; i < n; i++){
        cin >> a[i];
    }
    int max_height = 0;
    for(int i =0 ; i < n; i++){
        if(a[i] <= h){
            max_height += 1;
        } else{
            max_height += 2;
        }
    }
    cout << max_height << "\n";

}