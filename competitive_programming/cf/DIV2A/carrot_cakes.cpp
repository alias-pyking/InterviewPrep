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
	int n, t, k, d;
	cin >> n >> t >> k >> d;
	int curr_t = 0;
	while(curr_t <= d){
		n -= k;
		curr_t += t;
	}
	if(n > 0){
		cout << "YES\n";
	}
	else{
		cout << "NO\n";
	}
}