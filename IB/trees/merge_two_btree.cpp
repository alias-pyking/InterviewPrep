#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
TreeNode* merge_two_binary_trees(TreeNode* tree_0, TreeNode* tree_1){
	if(not tree_1) return tree_0;
	if(not tree_0) return tree_1;
	tree_0->val += tree_1->val;
	tree_0->left = merge_two_binary_trees(tree_0->left, tree_1->left);
	tree_0->right = merge_two_binary_trees(tree_0->right, tree_1->right);
	return tree_0;
}
int main(){

}

