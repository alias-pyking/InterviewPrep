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
int n, m, i, j, k;
int a[100074][2];

int main(){
	cin >> n >> k;
	fo(i, n) cin >> a[i][0] >> a[i][1];
	int x = 0;
	fo(i,n){
		x += a[i][1] - a[i][0] + 1;
	}
	if(x % k == 0){
		cout << 0 << "\n";
	} else{
		cout << (k - (x % k)) % k << "\n";	
	}
	
}