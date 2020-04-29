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
	ll n, k;
	cin >> n >> k;
	ll num_odd;
	if (n % 2 == 0){
		num_odd = n / 2;
	} else{
		num_odd = n / 2 + 1;
	}
	if(k <= num_odd){
		ll ans = 1 + (k - 1) * 2;
		cout << ans << "\n";
	} else{
		ll ans = 2 + (k - 1 - num_odd) * 2;
		cout << ans << "\n";
	}

}