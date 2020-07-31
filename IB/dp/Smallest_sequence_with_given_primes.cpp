#include<bits/stdc++.h>
using namespace std;

vector<int> get_seq(int a, int b, int c, int d){
    vector<int> dp(d + 1);
    int x = 0, y = 0, z = 0, n = d + 1;
    dp[0] = 1;
    for(int i = 1; i < n; i++){
        int temp = min(a*dp[x], b*dp[y], c*dp[z]);
        dp[i] = temp;
        if(temp == a*dp[x]) x++;
        else if(temp == b*dp[y]) y++;
        else z++;
    }
    reverse(dp.begin(), dp.end());
    dp.pop_back();
    reverse(dp.begin(), dp.end());
    return dp;
}

int main(){

}