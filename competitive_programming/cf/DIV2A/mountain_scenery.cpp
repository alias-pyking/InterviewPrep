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
#define fo(i, n) for (i = 0; i < n; i++)
#define Fo(i,k, n) for (i = k; i <= n; i++)
#define Foo(i, n) for (i = 1; i <= n; i++)
int n, m, a, k,i,j,t;
int arr[1000];

int main(){
	cin >> n >> k;
	n = 2 * n + 1;
	Foo(i, n) cin >> arr[i];
	for (i = 2; i < n; i+= 2){
		if(arr[i] > arr[i -1] + 1 and arr[i] > arr[i + 1] + 1 and k){
			arr[i]--;
			k--;
		}
		if(!k){
			break;
		}
	}
	Foo(i, n) cout << arr[i] << " ";
	cout << "\n";
}