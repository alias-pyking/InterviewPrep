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
    int a[n];
    for(int i = 0;i < n; i++){
        cin >> a[i];
    }
    int i =0, j = n - 1;
    int s = 0, d = 0;
    while(i <= j){
        if (a[i] > a[j]){
            s += a[i];
            i++;
            if (a[i] > a[j] and i <= j ){
                d += a[i];
                i++;
            } else if (i <= j){
                d += a[j];
                j--;
            }
        } else{
            s += a[j];
            j--;
            if (a[i] > a[j] and i <= j ){
                d += a[i];
                i++;
            } else if (i <= j){
                d += a[j];
                j--;
            }
        } 
    }
    cout << s << " "  << d <<"\n";
    return 0;
}