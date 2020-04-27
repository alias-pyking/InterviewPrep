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
	int n, b, d;
	cin >> n >> b >> d;
	int a[n];
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	int ans = 0;
	int total_size = 0;
	for (int i = 0; i < n;i++){
		if(a[i] <= b){
			total_size += a[i];
			if(total_size > d){
				ans++;
				total_size = 0;
			}
		}
	}
	cout << ans << "\n";
}