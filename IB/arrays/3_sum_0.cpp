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
vector<vi> threeSum(vector<int> &A) {	
	sort(A.begin(), A.end());
	int n = A.size();
	set<vector<int>> result;
	for (int i = 0; i < n  - 2; i++){
		int a = A[i];
		int left = i + 1, right = n - 1;
		while(left < right){
			long long int sum = (long long int)a + A[left] + A[right];
			if(sum == 0ll){
				vector<int> s;
				s.push_back(a);
				s.push_back(A[left]);
				s.push_back(A[right]);
				sort(s.begin(),s.end());
				result.insert(s);
				left++, right--;
			}
			else if(sum > 0){
				right--;
			} else {
				left++;
			}
		}
	}
	vector<vi> res;
	for(auto st: result){
	    res.push_back(st);
	}
	return res;
}

int main(){
	int t, q;
	int arr[] = {-5, 1, 4, -7, 10, -7, 0, 7, 3, 0, -2, -5, -3, -6, 4, -7, -8, 0, 4, 9, 4, 1, -8, -6, -6, 0, -9, 5, 3, -9, -5, -9, 6, 3, 8, -10, 1, -2, 2, 1, -9, 2, -3, 9, 9, -10, 0, -9, -2, 7, 0, -4, -3, 1, 6, -3};
	vi A;
	for(auto a: arr){
		A.push_back(a);
	}
	cout <<"sum is: " <<threeSumClosest(A, -1);
}

