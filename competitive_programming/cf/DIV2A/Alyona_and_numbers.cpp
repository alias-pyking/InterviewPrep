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
#include<iomanip>
using namespace std;
#define ll long long
#define fo(i,n) for (i = 0; i < n; i++)
int n, m, a, k,i,j,t;
int arr[1000];

struct point2d{
	double x,y;
};
struct rectangle{
	point2d lower;
	point2d upper;
};
int main(){
	cin >> n >> m;
	ll ans = 0;
	for (i = 1; i <= n; i++){
		ans += (m + i) / 5 - i / 5;
	}
	cout << ans << "\n";
	return 0;
}