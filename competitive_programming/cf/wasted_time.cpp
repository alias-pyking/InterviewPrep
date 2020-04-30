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
#define Fo(i,n) for (i = 1; i < n; i++)
int n, m, a, k,i,j;
int arr[1000];

struct point{
	int x,y;
};

double get_length(point a, point b){
	double t1 = pow(b.x - a.x, 2);
	double t2 = pow(b.y - a.y,2);
	double length = sqrt(t1 + t2);
	return length;
}

int main(){
	cin >> n >> k;
	point coordinate[n];
	fo(i,n) cin >> coordinate[i].x >> coordinate[i].y;
	double total_length = 0.0;
	Fo(i,n) total_length += get_length(coordinate[i],coordinate[i - 1]);
	double time_wasted = total_length/50;
	time_wasted *= (double)k;
	cout << setprecision(9) <<time_wasted << "\n";
}