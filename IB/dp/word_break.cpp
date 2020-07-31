#include<bits/stdc++.h>
using namespace std;

bool word_break(string str, vector<string> &dictionary){
    if(dictionary.empty()) return 0;
    unordered_set<string> dict;
    for(auto w: dictionary) dict.insert(w);
    int n = str.length();
    vector<bool> dp(n + 1, 0);
    dp[0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = i - 1; j >= 0; j--){
            if(dp[j]) {
                if(dict.find(str.substr(j, i - j)) != dict.end()){
                    dp[i] = 1;
                    break;
                }
            }
        }
    }
    return dp[n];
}
int main(){
    return 0;
}