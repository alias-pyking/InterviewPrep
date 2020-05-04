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
int a[124];

int main(){
	cin >> n;
	fo(i, n) cin >> a[i];
	bool flag = true;
	fo(i,n - 2){
		if(a[i] == a[i + 1]){
			if(a[i] == a[i + 2]){
				continue;
			} else{
				swap(a[i + 1], a[i + 2]);
			}
		}
	}
	fo(i,n - 1){
		if(a[i] == a[i + 1]){
			flag = false;
			break;
		}
	}
	if (flag)
	{
		cout << "YES\n";
	} else{
		cout << "NO\n";
	}
		
}