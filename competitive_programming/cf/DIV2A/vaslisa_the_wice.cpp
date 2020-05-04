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
int arr[1000];
int r1, r2, c1, c2, d1, d2;
void solve(){
	for (int i = 1; i <= 9; i++){
		for (int j = 1; j <= 9; j++){
			for (int k = 1; k <= 9; k++){
				for (int l = 1; l <= 9; l++){
					if (i != j and i != k and i != l and j!= k and j != l and k != l){
						if (i + j == r1 and k + l == r2 and i + k == c1 and j + l == c2 and i + l == d1 and j + k == d2){
						printf("%d %d\n", i, j);
						printf("%d %d\n", k, l);
						return;
						}
					}
				}
			}
		}
	}
	printf("-1\n");
}

int main(){
	cin >> r1 >> r2;
	cin >> c1 >> c2;
	cin >> d1 >> d2;
	solve();
}