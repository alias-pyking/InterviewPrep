#include<bits/stdc++.h>
using namespace std;
unordered_map<string,bool> dp;
bool f(string a, string b){
    if(a == b) return true;
    if(a.length() <= 1) return false;
    string temp = "";
    temp.append(a);
    temp.push_back('_');
    temp.append(b);
    if(dp.find(temp) != dp.end()) return dp[temp];
    int n = a.length();
    bool flag = false;
    for(int i = 1; i < n; i++){
        bool t1 = f(a.substr(0,i), b.substr(n - i, i)) and f(a.substr(i, n - i), b.substr(0, n - i));
        bool t2 = f(a.substr(0, i), b.substr(0, i)) and f(a.substr(i, n - i), b.substr(i, n - i));
        if(t1 or t2){
            flag = true;
            break;
        }
    }
    return dp[temp] = flag;
}
bool scrambled(const string A, const string B){
    if(A.length() != B.length()) return false;
    return f(A, B);

}

int main(){

}