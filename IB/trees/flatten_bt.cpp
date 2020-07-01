#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* flatten(TreeNode *root){
	TreeNode *current = root;
	stack<TreeNode *> stk;
	stk.push(NULL);
	while(current){
		if(current->right){
			stk.push(current->right);
		}
		if(current->left){
			current->right = current->left;
			current->left = NULL;
		} else {
			current->right = stk.top();stk.pop();
		}
		current = current->right;
	}
	return root;
}
int main(){
	TreeNode *root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->left->left = new TreeNode(3);
	root->right = new TreeNode(4);
	TreeNode *node = flatten(root);
	while(node){
		cout << node->val << ' ';
		node = node->right;
	}
	
}