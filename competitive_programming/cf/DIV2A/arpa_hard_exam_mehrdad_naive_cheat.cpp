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
int a[1000];

int get_last_digit(){
	if(n == 0){
		return 1;
	}
	if(n%4 == 0){
		return 6;
	}
	if(n%4 == 1){
		return 8;
	}
	if(n%4 == 2){
		return 4;
	}
	if(n%4 == 3){
		return 2;
	}
	
}
int main(){
    cin >> n;
	cout << get_last_digit() << "\n";
}