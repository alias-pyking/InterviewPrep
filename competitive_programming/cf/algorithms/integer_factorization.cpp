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
const int N = 1e5 + 24;
const int mod = 1e9 + 7;
ll n, m;
vl sieve_of_eratosthenes(ll n){
	vl primes;
	vector<bool> is_prime(n,true);
	is_prime[0] = is_prime[1] = false;
    for(ll i = 2; i * i <= n; i++){
        if(is_prime[i]) {
			primes.push_back(i);
			for(ll j = i * i; j <= n; j += i){
                is_prime[j] = false;
            }
        }
    }
	return primes;
}
// Integer factorization techniques
vl trial_division1(ll n){
	vl factorization;
	for (ll d = 2; d * d <= n; d++){
		while(n % d == 0){
			factorization.push_back(d);
			n /= d;
		}
	}
	if(n > 1){
		factorization.push_back(n);
	}
	return factorization;
}
// wheel optimaztion
vl trial_division2(ll n){
	vl factorization;
	while( n % 2 == 0){
		factorization.push_back(2);
		n /= 2;
	}
	for (ll d = 3; d * d <= n; d += 2){
		while( n % d == 0){
			factorization.push_back(d);
			n /= d;
		}
	}
	if(n > 1){
		factorization.push_back(n);
	}
	return factorization;
}
// further optimaztion to this algorithm
// this is most optimized algorithm for computing the prime factors
vl trial_division3(ll n){
	vl factorization;
	for(int d:{2,3,5}){
		while(n % d == 0){
			factorization.push_back(d);
			n /= d;
		}
	}
	static array<int, 8> increments = {4, 2, 4, 2, 4, 6, 2, 6};
	int i = 0;
	for (ll d = 7; d * d <= n; d += increments[i++]){
		while(n % d == 0){
			factorization.push_back(d);
			n /= d;
		}
		if(i == 8){
			i = 0;
		}
	}
	if(n > 1){
		factorization.push_back(n);
	}
	return factorization;	
}
// precomputed primes
// we need prime factors of a number so best way to do it is just precompute the prime
// numbers until sqrt(n) and then do the same for facotiraztion
vl trial_division4(ll n){
	vl primes = sieve_of_eratosthenes(sqrt(n));
	vl factorization;
	for(ll d: primes) {
		while(n % d == 0){
			factorization.push_back(d);
			n /= d;
		}
	}
	if(n > 1){
		factorization.push_back(n);
	}
	return factorization;
}
int main(){
	#ifndef ONLINE_JUDGE	
	OJ
	#endif
	int t, q;
	while(cin >> n){
		vl factors = trial_division4(n);
		int sz = factors.size();
		print_itr(factors, factors.size());
		puts("");
	}
}

