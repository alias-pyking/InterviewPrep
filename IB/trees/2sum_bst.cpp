#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
int two_sum(TreeNode *root, int k){
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
	int left = 0, right = result.size() - 1;
	while(left < right){
		int sum = result[left] + result[right];
		if(sum == k){
			return 1;
		}
		if(sum < k){
			left++;
		} else{
			right--;
		}
	}
	return 0;
}
int main(){
	int t, q;
}

