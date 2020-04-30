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
int n, m, a, k,i,j;
int arr[1000];

struct point2d{
	double x,y;
};
struct rectangle{
	point2d lower;
	point2d upper;
};
int no_overlap = 901212;
rectangle is_overlap(rectangle first, rectangle second){
	if((second.lower.x >= first.lower.x and second.lower.x <= first.upper.x) and (second.lower.y >= first.lower.y and second.lower.y <= first.upper.y)){
		double xl, yl;
		double xu, yu;
		xl = second.lower.x;
		yl = second.lower.y;
		xu = min(first.upper.x, second.upper.x);
		yu = min(first.upper.y, second.upper.y);
		rectangle res;
		res.lower.x = xl;
		res.lower.y = yl;
		res.upper.x = xu;
		res.upper.y = yu;
		return res;
	}
	if ((second.lower.x >= first.lower.x and second.lower.x <= first.upper.x) and (second.upper.y >= first.lower.y and second.upper.y <= first.upper.y)){
		double xl, yl;
		double xu, yu;
		xl = second.lower.x;
		yl = first.lower.y;
		xu = min(first.upper.x, second.upper.x);
		yu = min(first.upper.y, second.upper.y);
		rectangle res;
		res.lower.x = xl;
		res.lower.y = yl;
		res.upper.x = xu;
		res.upper.y = yu;
		return res;
	}
	if((second.upper.x >= first.lower.x and second.upper.x <= first.upper.x) and (second.upper.y >= first.lower.y and second.upper.y <= first.upper.y)){
		double xl, yl;
		double xu, yu;
		xl = first.lower.x;
		yl = max(first.lower.y, second.lower.y);
		xu = min(first.upper.x, second.upper.x);
		yu = min(first.upper.y, second.upper.y);
		rectangle res;
		res.lower.x = xl;
		res.lower.y = yl;
		res.upper.x = xu;
		res.upper.y = yu;
		return res;

	}
	if((second.upper.x >= first.lower.x and second.upper.x <= first.upper.x) and (second.lower.y >= first.lower.y and second.lower.y <= first.upper.y)){
		double xl, yl;
		double xu, yu;
		xl = first.lower.x;
		yl = second.lower.y;
		xu = min(first.upper.x, second.upper.x);
		yu = min(first.upper.y, second.upper.y);
		rectangle res;
		res.lower.x = xl;
		res.lower.y = yl;
		res.upper.x = xu;
		res.upper.y = yu;
		return res;
	} else{
		rectangle res;
		res.lower.x = no_overlap;
		res.lower.y = no_overlap;
		res.upper.x = no_overlap;
		res.upper.y = no_overlap;
		return res;
	}
}
int main(){
	cin >> n;
	rectangle rects[n*2];
	fo(i, n*2) cin >> rects[i].lower.x >> rects[i].lower.y >> rects[i].upper.x >> rects[i].upper.y;
	for (i = 0; i < n; i+=2){
		rectangle r = is_overlap(rects[i], rects[i + 1]);
		if(r.lower.x == no_overlap){
			cout << "No Overlap\n";
		} else{
			cout << r.lower.x << " " << r.lower.y << " " << r.upper.x << " " << r.upper.y << "\n";
		}
	}
}	