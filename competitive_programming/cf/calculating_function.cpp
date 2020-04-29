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
ll n, m;
int a[1000];

int main(){
    cin >> n;
	if(n%2 == 0){
		cout << n / 2 << "\n";
	} else{
		cout << -(n + 1) / 2;
	}
	return 0;
}