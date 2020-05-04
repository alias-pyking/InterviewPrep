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
ll n, m, a;

int main(){
	cin >> n;
	ll t = n;
	string res;
	while(t){
		if(t == 9){
			res += 9 + '0';
			break;
		}
		ll r = t % 10;
		r = 9 - r;
		if(r < t % 10){
			res += r + '0';
		} else{
			res += t % 10 + '0';
		}
		// cout << t << "\n";
		t = t / 10;
	}
	reverse(res.begin(), res.end());
	int i;
	int size = res.length();
	for (i = 0; i <size; i++){
		if(res[i] != '0'){
			break;
		}
	}
	for (; i < size; i++){
		cout << res[i];
	}
	cout << "\n";
}