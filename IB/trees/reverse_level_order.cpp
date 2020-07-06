#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
vector<int> reverse_levelorder(TreeNode* root){
	queue<TreeNode *> que;
	stack<int> stk;
	que.push(root);
	while(not que.empty()){
		TreeNode *current = que.front();que.pop();
		if(current->right){
			que.push(current->right);
		}
		if(current->left){
			que.push(current->left);
		}
		stk.push(current->val);
	}
	vector<int> result;
	while(not stk.empty()){
		result.push_back(stk.top());
		stk.pop();
	}
	return result;
}
int main(){
	int t, q;
}

