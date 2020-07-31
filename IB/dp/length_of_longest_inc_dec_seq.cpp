#include<bits/stdc++.h>
using namespace std;

vector<int> lis(const vector<int> &a){
    int n = a.size();
    vector<int> inc(n, 0);
    for(int i = 0; i < n; i++){
        inc[i] = 1;
        for(int j = i - 1; j >= 0; j--){
            if(a[j] < a[i] and inc[i] < inc[j] + 1){
                inc[i] = inc[j] + 1;
            }
        }
    }
    return inc;
}

vector<int> lds(const vector<int> &a){
    int n = a.size();
    vector<int> dec(n, 0);
    for(int i = n - 1; i >= 0; i--){
        dec[i] = 1;
        for(int j = i + 1; j < n; j++){
            if(a[i] > a[j] and dec[i] < dec[j] + 1){
                dec[i] = dec[j] + 1;
            }
        }
    }
    return dec;
}
int lids(const vector<int> &arr){
    vector<int> inc = lis(arr);
    vector<int> dec = lds(arr);
    int n = arr.size();
    int res = INT_MIN;
    for(int i = 0; i < n; i++){
        res = max(res, inc[i] + dec[i] - 1);
    }
    return res;
}


int main(){
    const vector<int> arr = {8, 6, 3, 4, 2, 1};
    vector<int> inc = lis(arr);
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << ' ';
    }
    puts("");
    for(int i = 0; i < 6; i++){
        cout << inc[i] << ' ';
    }
    puts("");
    vector<int> dec = lds(arr);
    for(int i =0; i < 6; i++){
        cout << dec[i] << ' ';
    }
    puts("");
    return 0;

}