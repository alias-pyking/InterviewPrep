#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fo(i,n) for (i = 0; i < n; i++)
int n, m, i, j;
struct day{
	int k;
	int l;
};
bool compare(day first, day second){
	double first_diff = (double)first.k / first.l;
	double second_diff = (double)second.k / second.l;
	return first_diff < second_diff;
}
int main(){
	ll f;
	cin >> n >> f;
	ll k[n], l[n];
	vector<pair<ll, ll>> days;
	fo(i, n) cin >> k[i] >> l[i], days.push_back(make_pair(min(2 * k[i], l[i]) - min(k[i], l[i]), i));
	sort(days.rbegin(), days.rend());
	ll ans = 0;
	fo(i,f){
		int pos = days[i].second;
		ans += min(2 * k[pos], l[pos]);
	}
	for (i = f; i < n; i++){
		int pos = days[i].second;
		ans += min(k[pos], l[pos]);
	}
	cout << ans << "\n";
	return 0;
}