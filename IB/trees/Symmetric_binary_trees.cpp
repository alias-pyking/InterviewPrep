#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
bool check_symmetry(TreeNode* subtree_0, TreeNode* subtree_1){
	if(!subtree_0 and !subtree_1){
		return true;
	} else if(subtree_0 and subtree_1){
		return subtree_0->val == subtree_1->val and
			   check_symmetry(subtree_0->left, subtree_1->right) and
			   check_symmetry(subtree_0->right, subtree_1->left);
	}
	return false;
}
int is_symetric(TreeNode* root) {
	return check_symmetry(root->left, root->right);
}
int main(){

}