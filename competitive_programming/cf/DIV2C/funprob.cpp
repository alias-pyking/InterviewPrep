#include <bits/stdc++.h>
using namespace std;
float n, m;
int main(){
	while(cin >>n >> m){
		if(n==0 and m == 0){
			break;
		}
		if(n > m)
			printf("0.000000\n");
		else {
			float p = m, q = n;
			float ans = (p + 1 - q) / (p + 1);
			printf("%.6f\n", ans);
		}
	}
}

