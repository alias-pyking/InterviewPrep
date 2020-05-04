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
char a[101][101];

string get_type(){
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			if(a[i][j] == 'C' or a[i][j] == 'M' or a[i][j] == 'Y'){
				return "#Color";
			}
		}
	}
	return "#Black&White";
}

int main(){
	cin >> n >> m;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			cin >> a[i][j];
		}
	}
	string type = get_type();
	cout << type << "\n";
}