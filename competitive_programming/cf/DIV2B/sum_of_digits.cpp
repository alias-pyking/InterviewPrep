#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fo(i,n) for (i = 0; i < n; i++)
int n, m, i, j, k;
int a[1000000];

int main(){
	string num;
	cin >> num;
	int len = num.length();
	int count = 0;
	while(len > 1){
		int sum = 0;
		for (int i = 0; i < len; i++){
			sum += num[i] - '0';
		}
		num = to_string(sum);
		len = num.length();
		count++;
	}
	cout << count << "\n";
}