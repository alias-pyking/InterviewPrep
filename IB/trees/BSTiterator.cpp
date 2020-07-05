#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class BSTIterator{
	BSTIterator(TreeNode *root);
	bool hasNext();
	int next();
};
stack<TreeNode*> stk;
BSTIterator::BSTIterator(TreeNode *root){
	stk = stack<TreeNode *>();
	while(root){
		stk.push(root);
		root = root->left;
	}
}
bool BSTIterator::hasNext(){
	return not stk.empty();
}
int BSTIterator::next(){
	TreeNode *next_node = stk.top();stk.pop();
	TreeNode *node = next_node->right;
	while(node){
		stk.push(node);
		node = node->left;
	}
	return next_node->val;
}
int main(){
	int t, q;
}

