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
int n, k,w,a;
vector<vector<int>> adjList;
bool visited[100074];
vector<int> topsort_result;
int parent[100074];

void topological_sort(int u){
	visited[u] = true;
	for(auto v:adjList[u]){
		if(!visited[v]){
			topological_sort(v);
		}
	}
	topsort_result.push_back(u);
}
int main(){
	cin >> n >> k;
	adjList.resize(n + 1);
	for (int i = 1; i <= k; i++){
		cin >> w;
		for (int j = 0; j < w; j++){
			cin >> a;
			adjList[i].push_back(a);
		}
	}
	for (int i = 1; i <= n; i++){
		if(!visited[i]){
			topological_sort(i);
		}
	}
	int p = 0;
	for (int i = n - 1; i >= 0;i--){
		int student = topsort_result[i];
		parent[student] = p;
		p = student;
	}
	// cout << "top sort result :\n";
	// for(auto x: topsort_result){
	// 	cout << x << " ";
	// }
	// cout << "\n";
	for (int i = 1; i <= n; i++){
		cout << parent[i] << "\n";
	}
}