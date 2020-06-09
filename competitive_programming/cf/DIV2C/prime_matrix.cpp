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
int n, m;
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
vector<int> next_prime(N);
void next_prime_() {
	for (int i = 1; i <= N; i++){
		int j = i;
		while(!is_prime[j]) j++;
		next_prime[i] = j;
	}
}
int main(){
	int t, q;
	sieve_of_eratosthenes();
	next_prime_();
	cin >> n >> m;
	int mat[n][m];
	fo(i, n){
		fo(j, m){
			cin >> mat[i][j];
		}
	}
	int add[n][m];
	fo(i, n){
		fo(j, m){
			add[i][j] = next_prime[mat[i][j]] - mat[i][j];
		}
	}
	int min_moves = INT_MAX;
	for(int i = 0; i < n; i++){
		int sum = 0;
		for (int j = 0; j < m; j++){
			sum += add[i][j];
		}
		min_moves = min(min_moves, sum);
	}
	for (int j = 0; j < m; j++){
		int sum = 0;
		for (int i = 0; i < n; i++){
			sum += add[i][j];
		}
		min_moves = min(min_moves, sum);
	}
	cout << min_moves << '\n';
	return 0;
}

