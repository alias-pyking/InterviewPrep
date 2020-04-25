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
    int a = 0;
    int d = 0;
    for (int i = 0; i < n; i++){
        char c;
        cin >> c;
        if (c == 'A'){
            a++;
        } else{
            d++;
        }
    }
    auto ans = "";
    if (a > d){
        ans = "Anton";
    } else if(d > a){
        ans = "Danik";
    } else{
        ans = "Friendship";
    }
    cout << ans <<"\n"; 
}