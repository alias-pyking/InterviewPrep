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
void buildSegmentTree(int *arr,int *segmentTree, int l, int r) {
    int mid = (l + r)/2;
    if(l == r) {
        segmentTree[l] = arr[l];
        return;
    }
    buildSegmentTree(arr, segmentTree,l,mid);
    buildSegmentTree(arr, segmentTree, mid + 1, r);
    segmentTree[l] = segmentTree[l*2 + 1] + segmentTree[l*2 + 1];
}
int main()
{
    int i, n, k, j;
    cin >> n;
    int arr[n];
    int m;
    m = 4 *n + 1;
    int segmentTree[m];
    buildSegmentTree(arr,segmentTree, 0, n - 1);
    return 0;

} 
 