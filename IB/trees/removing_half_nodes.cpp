#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
TreeNode* remove_half_nodes(TreeNode* root){
	if(not root) return NULL;
	root->left = remove_half_nodes(root->left);
	root->right = remove_half_nodes(root->right);
	if(not root->left and not root->right){
		return root;
	}
	if(root->left == NULL){
		TreeNode* node = root->right;
		free(root);
		return node;
	}
	if(root->right == NULL){
		TreeNode *node = root->left;
		free(root);
		return node;
	}
	return root;
}
int main(){
	int t, q;
}

