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
int n, m, a, i, j, k;
int arr[1000];

struct point2d{
	double x,y;
};
struct rectangle{
	point2d first;
	point2d second;
};
bool in_the_rectangle(point2d a, rectangle r){
	if(a.y > r.second.y and a.y < r.first.y and a.x > r.first.x and a.x < r.second.x){
		return true;
	}
	return false;
}

int main(){
	cin >> n;
	rectangle rects[n];
	fo(i,n) cin >> rects[i].first.x >> rects[i].first.y >> rects[i].second.x >> rects[i].second.y;
	cin >> m;
	point2d points[m];
	fo(i,m) cin >> points[i].x >> points[i].y;
	fo(i,m){
		int flag = 1;
		for(j = 0; j < n; j++){
			if(in_the_rectangle(points[i], rects[j])){
				flag = 0;
				cout <<"Point "<< i + 1 <<" is contained in figure "<< j + 1 <<"\n";
			}
		}
		if(flag){
			cout << "Point "<< i + 1 <<" is not contained in any figure\n";
		}
	}
	
}