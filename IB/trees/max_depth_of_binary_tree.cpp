#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
int direct_max_depth(TreeNode* root){
	if(not root){
		return -1;
	}
	if(not root->left and not root->right){
		return 1;
	}
	return 1 + max(direct_max_depth(root->left),direct_max_depth(root->right));
}
int max_depth(TreeNode* root){
	return direct_max_depth(root);
}
int main(){
}

