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
int n;
int used[30][30];
int a[30][30];
void color(int i, int j){
	if(i < 0 or i >= n or j < 0 or j>= n){
		return;
	}
	if(used[i][j] != 0 or a[i][j] == 0){
		return;
	}
	used[i][j] = 1;
	for (int l = -1; l <= 1; l++){
		for (int m = -1; m <= 1; m++){
			color(i + l, j + m);
		}
	}
}

int main(){
	int num = 1;
	while (scanf("%d",&n) == 1)
	{
		getchar();
		memset(used, 0, sizeof used);
		string line;
		for (int i = 0;i < n; i++){
			cin >> line;
			for (int j = 0;j < n; j++){
				a[i][j] = line[j] - '0';
			}
		}
		int cnt = 0;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				if(a[i][j] == 1 and used[i][j] == 0){
					color(i, j);
					cnt++;
				}
			}
		}
		cout << "Image number " << num << " contains "<< cnt<<" war eagles.\n";
		num++;
	}
}