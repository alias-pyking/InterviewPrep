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

vector<int> get_product(string s1, string s2){
	vector<int> num1;
	vector<int> num2;
	int n = s1.length();
	int m = s2.length();
	vector<int> result(n + m);
	for (int i = 0; i < result.size(); i++){
		result[i] = 0;
	}
	if (n == 1 and s1[0] == 0)
	{
		vector<int> t;
		t.push_back(0);
		return t;
	}
	if(m == 1 and s2[0] == 0){
		vector<int> t;
		t.push_back(0);
		return t;
	}
	for (int i = 0; i < n; i++){
		num1.push_back(s1[i] - '0');
	}
	for (int i = 0; i < m; i++){
		num2.push_back(s2[i] - '0');
	}
	for (int i = n - 1; i >= 0; i--){
		for (int j = m - 1; j >= 0; j--){
			result[i + j + 1] += num1[i] * num2[j];
			result[i + j] += result[i + j + 1] / 10;
			result[i + j + 1] %= 10;
		}
	}
	return result;
}

int main(){
	string input;
	string s1, s2;
	cin >> s1 >> s2;
	vector<int> result = get_product(s1, s2);
	int i = 0;
	while (result[i] == 0)
	{
		i++;
	}
	int n = result.size();
	for (; i < n; i++){
		cout << result[i];
	}
	cout << "\n";
}