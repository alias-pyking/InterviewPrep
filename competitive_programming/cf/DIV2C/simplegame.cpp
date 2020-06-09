#include<iostream>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    if(n == 1) {
        cout << 1 << '\n';
        return 0;
    } 
    if(m - 1 < n - m){
        cout << m + 1 << '\n';
    } else {
        cout << m - 1 << '\n';
    }
    return 0;
}