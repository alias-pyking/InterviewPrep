#include<bits/stdc++.h>
using namespace std;

vector<int> solve(int c, vector<int> &strengths) {
    int n = strengths.size();
    int min_strength = INT_MAX;
    vector<int> candidate_strengths;
    unordered_map<int,int> idx_of;
    for(int i = 0; i < n; i++){
        if(strengths[i] < min_strength) {
            min_strength = strengths[i];
            candidate_strengths.push_back(strengths[i]);
            idx_of[strengths[i]] = i;
        }
    }
    n = candidate_strengths.size();
    vector<int> result;
    int i =0;
    while(i < n){
        int current_strength = candidate_strengths[i];
        if(current_strength <= c){
            int c_left = c - current_strength;
            int max_hits = c / min_strength;
            int cur_hits = 1 + c_left/ min_strength;
            if(cur_hits == max_hits){
                result.push_back(idx_of[current_strength]);
                c -= current_strength;
                continue;
            }
        }
        i++;
    }
    return result;
}

int main(){
    return 0;
}