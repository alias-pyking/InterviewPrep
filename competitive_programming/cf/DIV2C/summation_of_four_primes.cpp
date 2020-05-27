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
const int N = 1e7 + 1;
const int mod = 1e9 + 7;
int n;
vector<bool> is_prime(N,true);
vector<int> primes;
void sieve_of_eratosthenes(){
    is_prime[0] = is_prime[1] = false;
    for(int i = 2; i * i < N; i++){
        if(is_prime[i]) {
            primes.push_back(i);
            for(int j = i * i; j < N; j += i){
                is_prime[j] = false;
            }
        }
    }
}
void Num(int x, int &a, int &b){
    for(int i = 2; i <= x/2; i++){
        if(is_prime[i] and is_prime[x-i]){
            a = i;
            b = x - i;
            return;
        }
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    OJ
    #endif
    int m;
    sieve_of_eratosthenes();
    int sz = primes.size();
    while(cin >> n){
        if(n < 8) {print("Impossible.");}
        else if(n % 2 != 0){
            printf("2 3");
            int a,b;
            Num(n - 5, a, b);
            printf(" %d %d\n",a,b);
        } else {
            printf("2 2");
            int a,b;
            Num(n - 4, a, b);
            printf(" %d %d\n",a,b);
        }
    }
}
