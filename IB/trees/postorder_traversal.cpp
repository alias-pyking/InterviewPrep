#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
vector<int> postorderTraversal(TreeNode* root) {
	stack<TreeNode *> path_stack;
	vector<int> result;
	path_stack.push(root);
	while(!path_stack.empty()){
		TreeNode *current = path_stack.top();
		path_stack.pop();
		if(current){
			result.push_back(current->val);
			path_stack.push(current->left);
			path_stack.push(current->right);
		}
	}
	reverse(result.begin(), result.end());
	return result;
}

int main(){

}