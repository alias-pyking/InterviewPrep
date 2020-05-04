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
struct student
{
	int skill;
	int idx;
};
bool compare(student a, student b){
	if(a.skill < b.skill){
		return 1;
	}
	return 0;
}

int main(){
    int n;
    cin >> n;
	student a[n];
	for (int i = 0; i < n; i++){
		cin >> a[i].skill;
		a[i].idx = i;
	}
	sort(a, a + n, compare);
	int i = 0, j = 0, k = 0;
	for (i = 0; i < n; i++){
		if (a[i].skill == 2){
			j = i;
			break;
		}
	}
	for (i = 0; i < n; i++){
		if (a[i].skill == 3){
			k = i;
			break;
		}
	}
	i = 0;
	if(j == 0 or k == 0){
		cout << 0 << "\n";
	} else {
		int s1 = j - i;
		int s2 = k - j;
		int s3 = n - k;
		int w = min(s1, min(s2, s3));
		cout << w << "\n";
		int idx = 0;
		while (idx < w )
		{
			cout << a[i].idx + 1 << " " << a[j].idx + 1 << " " << a[k].idx + 1<< "\n";
			idx++;
			i++;
			j++;
			k++;
		}
	}
}