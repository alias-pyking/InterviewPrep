#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
int answer = 0
int dfs(TreeNode *root){
    if(root == NULL) return 0;
    int x = dfs(root->left);
    int y = dfs(root->right);
    answer = max(answer, x + y + root->val);
    return max(0, max(x, y) + root->val);
}
int max_path_sum(TreeNode *root){
    answer = INT_MIN;
    dfs(root);
    return answer;
} 