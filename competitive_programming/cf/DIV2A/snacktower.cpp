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
    int n;
    cin >> n;
	int a;
	int has[n + 1];
	memset(has, 0, sizeof has);
	int next = n;
	for (int i = 0; i < n; i++){
		cin >> a;
		has[a]++;
		if(has[next]){
			cout << next << " ";
			next = next - 1;
			for (; next >= 1; next--){
				if(has[next]){
					cout << next << " ";
				} else {
					break;
				}
			}
			cout << "\n";
		} else{
			cout << "\n";
		}
	}
}