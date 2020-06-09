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
const int N = 1e7 + 24;
const int mod = 1e9 + 7;
ll n, m;
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
int main(){
	sieve_of_eratosthenes();
	cin >> n;
	fo(i, n){
		ll a;
		cin >> a;
		ll r = sqrt(a);
		if(r * r == a and is_prime[sqrt(a)])
			printf("YES\n");
		else printf("NO\n");
	}
}

