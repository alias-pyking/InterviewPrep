#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fo(i,n) for (i = 0; i < n; i++)
int n, m, i, j, k;
int a[75];

int gcd(int a, int b){
	if (b == 0)
		return a;
	return gcd(b,a%b);
}

int common_factors(int a, int b){
	int _n = gcd(a, b);
	int res = 0;
	for (k = 2; k <= sqrt(_n); k++){
		if(n%k == 0){
			if(n/k == k)
				res += 1;
			else
				res += 2;
		}	
	}
	return res;
}

int main(){
	while (1)
	{
		cin >> n;
		if(n == 0){
			break;
		}
		fo(i, n) cin >> a[i];
		int cp = 0;
		for (i = 0; i < n; i++){
			for (j = i + 1; j < n; j++){
				if(gcd(max(a[i],a[j]),min(a[i],a[j])) == 1){
					cp++;
				}
			}
		}
		if(!cp){
			printf("No estimate for this data set.\n");
		} else{
			double pi = sqrt(6.000000 * (n * (n - 1) / 2) / cp);
			printf("%.6f\n", pi);
		}
	}
	
}