#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
int kthsmallest(TreeNode *root, int k){
	stack<TreeNode*> stk;
	vector<int> result;
	while(root or not stk.empty()){
		if(root){
			stk.push(root);
			root = root->left;
		} else{
			TreeNode* node = stk.top();stk.pop();
			result.push_back(node->val);
			root = node->right;
		}
	}
	return result[k - 1];
}
int main(){
	int t, q;
}

