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
    ll n, x, d,distressed_kids = 0;
	cin >> n >> x;
	char t;
	for (int i = 0; i < n; i++){
		cin >> t;
		cin >> d;
		if(t == '+'){
			x += d;
		}
		if (t == '-'){
			if(x >= d){
				x -= d;
			}
			else{
				distressed_kids++;
			}
		}
	}
	cout << x << " " << distressed_kids << "\n";
	return 0;
}