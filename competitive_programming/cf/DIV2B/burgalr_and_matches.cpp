#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fo(i,n) for (i = 0; i < n; i++)
ll n, m, i, j, k;
struct container{
	ll a;
	ll b;
};
bool compare_container(container lhs, container rhs){
	return lhs.b > rhs.b;
}
int main(){
	cin >> n >> m;
	container A[m];
	fo(i, m) cin >> A[i].a >> A[i].b;
	sort(A, A + m, compare_container);
	ll ans = 0;
	for(i = 0; i < m and n > 0; i++){
		if(n > A[i].a){
			ans += A[i].a * A[i].b;
			n = n - A[i].a;
		} else {
			ans += n * A[i].b;
			n = 0;
		}
	}
	cout << ans << "\n";
}