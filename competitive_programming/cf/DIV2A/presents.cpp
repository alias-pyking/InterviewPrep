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
	int a[n + 1];
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	int result[n + 1];
	for (int i = 1; i <= n; i++) {
		result[a[i]] = i;
	}
	for(int i = 1; i <= n; i++){
		cout << result[i] << " ";
	}
	cout << "\n";
	return 0;
}