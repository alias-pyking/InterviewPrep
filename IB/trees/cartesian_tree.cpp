#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
int max(vector<int> arr, int s, int e){
	int max = arr[s], max_index = s;
	for (int i = s; i <= e; i++){
		if(max < arr[i]){
			max = arr[i];
			max_index = i;
		}
	}
	return max_index;
}
TreeNode* build_tree_util(vector<int> inorder, int start, int end){
	if(start > end) return NULL;
	int max_index = max(inorder, start, end);
	TreeNode *root = new TreeNode(inorder[max_index]);
	root->left = build_tree_util(inorder, start, max_index - 1);
	root->right = build_tree_util(inorder, max_index + 1, end);
	return root;
}
TreeNode *build_tree(vector<int> &inorder){
	build_tree_util(inorder, 0, inorder.size() - 1);
}