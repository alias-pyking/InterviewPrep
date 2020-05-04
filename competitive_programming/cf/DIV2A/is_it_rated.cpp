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
int n, m;
int a[1001][2];

string is_it_rated(int a[][2], int n){
	for (int i = 0;i < n; i++){
		if(a[i][0] != a[i][1]){
			return "rated\n";
		}
	}
	bool flag = true;
	for (int i = 1; i < n; i++){
		if(!(a[i][0] <= a[i - 1][0])){
			return "unrated\n";
		}
	}
	return "maybe\n";
}
int main(){
    cin >> n;
	for (int i = 0; i < n; i++){
		cin >> a[i][0] >> a[i][1];
	}
	string ans = is_it_rated(a, n);
	cout << ans;
}