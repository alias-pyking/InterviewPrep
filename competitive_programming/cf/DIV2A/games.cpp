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
    int n,ans = 0;
    cin >> n;
    int a[n][2];
    for(int i = 0; i < n; i++){
        cin >> a[i][0] >> a[i][1];
    }
    for(int i = 0;i < n; i++){
        int j = i - 1, k = i + 1;
        while(j >= 0){
            if(a[i][0] == a[j][1]){
                ans++;
            }
            j--;
        }
        while(k < n) {
            if(a[i][0] == a[k][1]){
                ans++;
            }
            k++;
        }
    }
    cout << ans << "\n";
    return 0;
}