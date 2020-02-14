#include <iostream>
#include<vector>
#include<math.h>
#include<algorithm>
#include<set>
#include<unordered_map>
#include<map>
#include<unordered_set>
#include<cmath>
#include<stack>
#include<unordered_map>
#include<queue>
#include<map>
#include<cstring>
#include<limits.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;i<n;i++)
#define ll long long
#define pii pair<int,int>
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define clr(x) memset(x, 0, sizeof(x))
#define init(x, a) memset(x, a, sizeof(x))
 
const int mod = 1000000007;
int mpow(int base, int exp); 
const int N = 1e5+4;



/* Range minimum query segment tree */
void build_tree(int *arr, int *segment_tree,int i, int s, int e) {
    if(s > e) {
        return;
    }
    if(s == e) {
        segment_tree[i] = arr[s];
        return;
    }
    int mid = (s + e)/2;
    build_tree(arr, segment_tree, 2 * i + 1, s , mid);
    build_tree(arr, segment_tree, 2 * i + 2, mid + 1, e);
    int left  = segment_tree[2 * i + 1];
    int right = segment_tree[2 * i + 2];
    segment_tree[i] = min(left, right);
}

int get_range_min(int *arr, int *segment_tree,int i, int s, int e, int qs, int qe) {
    // No overlap
    if(qs > e or qe < s) {
        return INT_MAX;
    }
    // Complete overlap
    if(s >= qs and e <= qe) {
        return segment_tree[i]; 
    }
    // Partial overlap
    int mid = (s + 2) /2;
    int leftAns = get_range_min(arr, segment_tree, 2 * i + 1, s, mid, qs, qe);
    int rightAns = get_range_min(arr, segment_tree, 2 * i + 2, mid + 1, e, qs, qe);
    return min(leftAns, rightAns);
}

void update(int *arr, int *segment_tree,int i, int idx, int value)
/**********************************/

int main()
{
    int i, n, k, j;
    cin >> n;
    int arr[n];
    fo(i,n) cin >> arr[i];
    int *segment_tree = new int[4*n + 1];
    build_tree(arr, segment_tree,0, 0, n - 1);

    return 0;

} 
 