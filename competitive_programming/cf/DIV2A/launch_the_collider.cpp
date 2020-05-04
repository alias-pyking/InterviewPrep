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
#include<limits.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include<iomanip>
using namespace std;
#define ll long long
#define fo(i,n) for (i = 0; i < n; i++)
ll n, m, k, i, j, t;
ll a[200098];
int main(){
	cin >> n;
	string direction;
	cin >> direction;
	fo(i, n) cin >> a[i];
	bool flag = false;
	ll ans = LONG_MAX;
	fo(i,n - 1){
		if(direction[i] == 'R' and direction[i + 1] == 'L'){
			flag = true;
			ans = min((a[i + 1] - a[i]) / 2,ans);
		}
	}
	if(flag){
		cout << ans << "\n";
	} else{
		cout << -1 << "\n";
	}

}