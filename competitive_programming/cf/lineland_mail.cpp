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
ll get_distance(ll *a, int i){
	if(a[i] < 0 and a[i + 1] < 0){
			ll d = abs(a[i]) - abs(a[i + 1]);
			return d;
		}
	else if(a[i] < 0){
		ll d = -a[i] + a[i + 1];
		return d;
	} else{
		ll d = a[i + 1] - a[i];
		return d;
	}
}
int main(){
    int n;
    cin >> n;
	ll a[n];
	for (int i = 0;i < n; i++){
		cin >> a[i];
	}
	ll max_distances[n];
	ll min_distances[n];
	for (int i = 0; i < n; i++){
		max_distances[i] = max(abs(a[i] - a[0]), abs(a[i] - a[n - 1]));
	}
	min_distances[0] = abs(a[0] - a[1]);
	min_distances[n - 1] = abs(a[n - 1] - a[n - 2]);
	for (int i = 1; i < n - 1; i++){
		min_distances[i] = min(abs(a[i] - a[i - 1]), abs(a[i] - a[i + 1]));
	}
	for (int i = 0; i < n; i++){
		cout <<  min_distances[i] << " " << max_distances[i] << "\n";
	}
	return 0;
}