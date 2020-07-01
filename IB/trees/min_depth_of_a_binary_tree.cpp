#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
int direct_min_depth(TreeNode* root){
	if(not root){
		return INT_MAX;
	}
	if(not root->left and not root->right){
		return 1;
	}
	return 1 + min(direct_min_depth(root->left), direct_min_depth(root->right));
}
int min_depth(TreeNode* root){
	return direct_min_depth(root);
}
int main(){
}

