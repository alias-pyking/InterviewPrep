#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
void path_helper(TreeNode* root, vector<int> &current_path, int key){
	if(root == NULL) return;
	if(root->val == key){
		current_path.push_back(root->val);
		return;
	}
	current_path.push_back(root->val);
	path_helper(root->left, current_path,key);
	path_helper(root->right, current_path, key);
	current_path.pop_back();
	return;
}
vector<int> path(TreeNode* root, int key){
	vector<int> path_to_node;
	path_helper(root, path_to_node, key);
	return path_to_node;
}
int main(){
}

