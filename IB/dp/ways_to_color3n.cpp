#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
int ways(int n) {
	long int color3 = 24;
	long int color2 = 12;
	long int temp = 0;
	for (int i = 2; i <= n; i++){
		temp = color3;
		color3 = (11 * color3 + 10 * color2) % mod;
		color2 = (5 * temp + 7 * color2) % mod;
	}
	long num = (color3 + color2) % mod;
	return (int)num;
}

int main() {

}