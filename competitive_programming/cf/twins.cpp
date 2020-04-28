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

int get_sum(int i, int j, int *a){
	int ans = 0;
	for (; i <= j; i++){
		ans += a[i];
	}
	return ans;
}

int main(){
    int n;
    cin >> n;
	int a[n];
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	sort(a, a + n);
	int num_coins = 1;
	int my_sum = a[n - 1];
	for (int i = n - 2; i >= 0; i--){
		int remaining_sum = get_sum(0, i,a);
		if(my_sum > remaining_sum){
			break;
		} else{
			my_sum += a[i];
			num_coins++;
		}
	}
	cout << num_coins;
}