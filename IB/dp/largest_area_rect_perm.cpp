#include<bits/stdc++.h>
using namespace std;

int area(vector<vector<int>> &mat){
    int n = mat.size(), m = mat[0].size();
    vector<vector<int>> hist(n,vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(i == 0){
                hist[i][j] = mat[i][j];
            } else {
                hist[i][j] = mat[i][j] == 1 ? hist[i - 1][j]: 0;
            }
        }
    }
    for (int i = 0; i < n; i ++) {
            int count[n + 1] = {0};
            for (int j = 0; j < m; j ++) {
                count[hist[i][j]] ++;
            }
            int col = 0;
            // runs R + C
            for (int k = n; k >= 0; k --) {
                // runs C times
                while (count[k] > 0) {
                    hist[i][col++] = k;
                    count[k]--;
                }
            }   
    }
    int curr_area, max_area = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            curr_area = (j + 1)*hist[i][j];
            max_area = max(max_area, curr_area);
        }
    }
    return max_area;
}

int main(){
    vector<vector<int>>a = {{1,0,1},{1,0,1},{1,0,1}};
    area(a);
}