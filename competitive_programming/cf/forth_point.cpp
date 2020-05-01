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
	double x1, y1, x2, y2, x3, y3, x4, y4;
	double x, y;
	while(cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4){
		if(x1== x3 and y1 == y3){
			x = x2 + x4 - x3;
			y = y2 + y4 - y3;
		} else if(x1 == x4 and y1 == y4){
			x = x2 + x3 - x4;
			y = y2 + y3 - y4;
		} else if(x2 == x3 and y2 == y3){
			x = x1 + x4 - x3;
			y = y1 + y4 - y3;
		} else{
			x = x1 + x3 - x4;
			y = y1 + y3 - y4;
		}
		printf("%.3f %.3f\n", x, y);
	}
}