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
bool is_overlap(rectangle R1, rectangle R2){
	if((R1.lower.x <= R2.upper.x and R1.upper.x >= R2.lower.x)\
		and (R1.lower.y <= R2.upper.y and R1.upper.y >= R2.lower.y)){
		return true;
	}
	return false;
}
int main(){
	cin >> n;
	while(n--){
		rectangle R1;
		rectangle R2;
		cin >> R1.lower.x >> R1.lower.y >> R1.upper.x >> R1.upper.y;
		cin >> R2.lower.x >> R2.lower.y >> R2.upper.x >> R2.upper.y;	
		int xl = max(R1.lower.x, R2.lower.x);
		int yl = max(R1.lower.y, R2.lower.y);
		int xu = min(R1.upper.x, R2.upper.x);
		int yu = min(R1.upper.y, R2.upper.y);
		if(xl >= xu or yl >= yu){
			puts("No Overlap");
		}
		else{
			printf("%d %d %d %d\n", xl, yl, xu, yu);
		}
		if(n)
			puts("");
	}
}	