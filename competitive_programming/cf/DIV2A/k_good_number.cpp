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
	cin >> n >> k;
	string ss = "0123456789";
	string s;
	int ret = -1;
	int count1 = 0, count2 = 0;
	while (n--)
	{
		/* code */
		cin >> s;
		for (i = 0; i <= k; i++){
			ret = s.find(ss[i]);
			if(ret != -1){
				count1++;
				ret = -1;
			}
		}
		if(count1 >= k + 1){
			count2++;
		}
		count1 = 0;
	}
	
	cout << count2 << "\n";
	return 0;
}