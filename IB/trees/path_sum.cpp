#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
bool check_has_sum(TreeNode* tree,int current_sum, int sum){
	if(!tree) return false;
	if(!tree->left and !tree->right){
		cout << "current_sum : " << current_sum << '\n';
		cout << "tree " << tree->val << '\n';
		current_sum = current_sum + tree->val;
		cout << "current_sum after " << current_sum << '\n';
		if(current_sum == sum){
			return true;
		}
		return false;
	}
	return check_has_sum(tree->left, current_sum + tree->val, sum) or
		   check_has_sum(tree->right, current_sum + tree->val, sum);
}
int has_path_sum(TreeNode* tree, int sum){
	return check_has_sum(tree, 0, sum);
}
int main(){
	TreeNode *root = new TreeNode(1000);
	root->left = new TreeNode(2000);
	root->left->left = new TreeNode(-3001);
	cout << has_path_sum(root, -1);

}