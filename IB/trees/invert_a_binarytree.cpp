#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
TreeNode* invert_btree(TreeNode* root){
	if(not root) return nullptr;
	TreeNode *left = invert_btree(root->left);
	TreeNode *right = invert_btree(root->right);
	root->left = right;
	root->right = left;
	return root;
}

int main(){
}

