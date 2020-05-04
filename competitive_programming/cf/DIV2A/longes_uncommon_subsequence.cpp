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
	string s1;
	string s2;
	cin >> s1;
	cin >> s2;
	int i = 0, j = 0;
	int n = s1.length(), m = s2.length();
	if(s1 == s2) {
		cout << -1 << "\n";
	} else if(n > m){
		cout << n << "\n";
	} else if(m > n){
		cout << m << "\n";
	} else{
		cout << n << "\n";
	}
	return 0;
}