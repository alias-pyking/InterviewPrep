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
    set<char> username_set;
    string username;
    cin >> username;
    int n = username.length();
    for(int i = 0;i < n; i++){
        username_set.insert(username[i]);
    }
    int size = username_set.size();
    if(size %2 == 0){
        cout << "CHAT WITH HER!\n";
    } else{
        cout << "IGNORE HIM!\n";
    }

}