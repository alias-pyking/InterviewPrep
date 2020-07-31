#include <bits/stdc++.h>
using namespace std;
int anytwo(string x){
	string y = x;
	int count = 0;
	int idx = 0;
	for (int i = 0; i < y.length(); i++){
		int j = idx;
		while(j < x.length()){
			if(y[i] == x[j] and i != j){
				count++;
				idx = ++j;
				break;
			} else {
				j++;
			}
		}
	}
	return count >= 2;
}
int main(){
	int t, q;
}

