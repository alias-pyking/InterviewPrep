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
int a[101];

int main(){
    cin >> n;
	memset(a, 0, sizeof a);
	int p1, p2;
	cin >> p1;
	for (int i = 0; i < p1; i++){
		cin >> m;
		a[m] = 1;
	}
	cin >> p2;
	for (int i = 0; i < p2; i++){
		cin >> m;
		a[m] = 1;
	}
	int flag = 0;
	for (int i = 1; i <= n; i++){
		if(a[i] == 0){
			flag = 1;
			break;
		}
	}
	if(flag){
		cout << "Oh, my keyboard!\n";
	} else{
		cout << "I become the guy.\n";
	}
	return 0;
}