#include<bits/stdc++.h>
using namespace std;

int lvp(string parenthesis) {
	stack<int> indices;
	indices.push(-1);
	int res = 0, n = parenthesis.size();
	for (int i = 0; i < n; i++){
		if(parenthesis[i] == '(') indices.push(i);
		else {
			indices.pop();
			if(not indices.empty()) {
				res = max(res, i - indices.top());
			} else {
				indices.push(i);
			}
		}
	}
	return res;
}

int main() {

}