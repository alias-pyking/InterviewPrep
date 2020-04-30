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
#define fo(i,n) for (i = 0; i < n; i++)
ll l, r, a, k;
ll gcd(ll a, ll b)
{
  if (b == 0)
  {
    return a;
  }
  else
  {
    return gcd(b, a % b);
  }
}

int main(){
	cin >> l >> r;
	if(l % 2 != 0){
		l++;
	}
	if(l + 2 > r){
		cout << -1 << "\n";
	} else{
		cout<< l << " "<< l + 1 << " "<< l + 2<<"\n";
	}
}