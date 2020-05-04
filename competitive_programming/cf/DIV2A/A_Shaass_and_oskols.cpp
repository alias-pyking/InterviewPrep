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
    int n,m,wire,bird;
    cin >> n;
	int a[n];
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	cin >> m;
	for (int i = 0; i < m; i++){
		cin >> wire >> bird;
		if(wire - 2 >= 0){
			a[wire - 2] += bird - 1;
		}
		a[wire - 1] -= bird;
		if(wire < n){
			a[wire] += a[wire - 1];
		}
		a[wire - 1] -= a[wire - 1];
		
	}
	for (int i = 0; i < n; i++){
		cout << a[i] << "\n";
	}
	return 0;
}