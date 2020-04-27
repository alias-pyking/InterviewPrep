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
    int y,w;
	cin >> y >> w;
	int m = max(y,w);
	switch (m)
	{
	case 1:
		cout <<"1/1"<< "\n";
		break;
	case 2:
		cout << "5/6" << "\n";
		break;
	case 3:
		cout << "2/3" << "\n";
		break;
	case 4:
		cout << "1/2"<< "\n";
		break;
	case 5:
		cout << "1/3" << "\n";
		break;
	case 6:
		cout << "1/6" << "\n";
		break;
	}
}