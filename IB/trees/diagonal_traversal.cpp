#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
void diagonal_traversal_util(TreeNode* node, int level, map<int, vector<int>> &diagonal){
	if(not node) return;
	diagonal[level].push_back(node->val);
	diagonal_traversal_util(node->left, level + 1, diagonal);
	diagonal_traversal_util(node->right, level, diagonal);
}
int main(){
	int t, q;
}

