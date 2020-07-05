#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
int post_index;
TreeNode* build_tree_util(vector<int> &inorder, vector<int> &postorder, int in_st, int in_en, unordered_map<int,int> node_to_idx){
	if(in_st > in_en) return NULL;
	TreeNode* root = new TreeNode(postorder[post_index--]);
	if(in_st == in_en) return root;
	int root_idx = node_to_idx[root->val];
	root->left = build_tree_util(inorder, postorder, in_st, root_idx - 1, node_to_idx);
	root->right = build_tree_util(inorder, postorder, root_idx + 1, in_en, node_to_idx);
	return root;
}
TreeNode* build_tree(vector<int> &inorder, vector<int> &postorder){
	post_index = postorder.size() - 1;
	unordered_map<int, int> node_to_idx;
	int n = inorder.size();
	for (int i = 0; i < n; i++){
		node_to_idx[inorder[i]] = i;
	}
	return build_tree_util(inorder, postorder, 0, n - 1, node_to_idx);
}
int main(){

}

