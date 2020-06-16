#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pi;
typedef vector<pair<int, int>> vpi;
typedef vector<pair<ll, ll>> vpl;
typedef vector<pair<double, double>> vpd;

#define maxvec(vec) *max_element(vec.begin(), vec.end())
#define minvec(vec) *min_element(vec.begin(), vec.end())
#define fo(i, n) for (int i = 0; i < n; i++)
#define Fo(i, n) for (int i = 1; i <= n; i++)
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define SQ(a) (a)*(a)
#define print(var) cout << var << "\n";
#define print_itrn(seq, n) fo(i, n) print(seq[i])
#define print_itr(seq, n) fo(i, n) cout << seq[i] << " ";
#define OJ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

const int N = 2e7 + 24;
const int mod = 1e9 + 7;
int n;
vector<bool> is_prime(N,true);
void sieve_of_eratosthenes(){
    is_prime[0] = is_prime[1] = false;
    for(int i = 2; i * i <= N; i++){
        if(is_prime[i]) {
            for(int j = i * i; j <= N; j += i){
                is_prime[j] = false;
            }
        }
    }
}
ll lcm(ll a, ll b){
    return (a * b) / __gcd(a, b);
}
ll bigmod(ll b, ll p, ll m = mod){
	ll res = 1;
	while(p){
		if(p & 1)
			res = (res * b) % m;
		b = (b * b) % m;
		p >>= 1; // dividing p by 2
	}
	return res;
}
ll bigpow(ll b, ll p){
	ll res = 1;
	while(p){
		if(p & 1)
			res = (res * b);
		b = (b * b);
		p >>= 1; // dividing p by 2
	}
	return res;
}
// extended Euclid's algorithm
int extended_euclid_gcd(int a, int b, int &x, int &y){
    if(a > b){
        return extended_euclid_gcd(b, a, x, y);
    }
    if(a == 0){
        x = 0;
        y = 1;
        return b;
    }
    int x1, y1;
    int ans = extended_euclid_gcd(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return ans;
}
int main(){
    #ifndef ONLINE_JUDGE
    OJ
    #endif
    int m;
    while(cin >> n >> m){
        print(lcm(n, m));
    }

}
