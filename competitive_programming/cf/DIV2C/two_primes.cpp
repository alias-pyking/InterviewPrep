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
const int N = 2e7 + 1;
const int mod = 1e9 + 7;
int n;
vector<bool> is_prime(N,true);
vector<int> twin_primes(N + 5);
void sieve_of_eratosthenes(){
    is_prime[0] = is_prime[1] = false;
    for(int i = 2; i * i < N; i++){
        if(is_prime[i]) {
            for(int j = i * i; j < N; j += i){
                is_prime[j] = false;
            }
        }
    }
}
void twin_prime(){
    int j = 1;
    for(int i = 3; i < N; i++){
        if(is_prime[i] and is_prime[i + 2]){
            twin_primes[j++] = i;
        }
    }

}
int main(){
    #ifndef ONLINE_JUDGE
    OJ
    #endif
    int m;
    sieve_of_eratosthenes();
    twin_prime();
    while(cin >> n){
        printf("(%d, %d)\n",twin_primes[n], twin_primes[n] + 2);
    }
    
    
}
