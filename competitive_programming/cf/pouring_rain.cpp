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
double d, h, v, e;
int arr[1000];

struct point2d{
	double x,y;
};
struct rectangle{
	point2d lower;
	point2d upper;
};
int main(){
	cin >> d >> h >> v >> e;
	double s = (3.14 * pow(d, 2)) / (4 * v);
	if(s > e){
		double t = (4 * v) / (3.14 * pow(d, 2));
		double ans = h / ( t- e);
		cout << "YES\n";
		cout << setprecision(9) << ans << "\n";
	} else{
		cout << "NO\n";
	}
}