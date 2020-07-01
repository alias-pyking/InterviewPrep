#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
	queue<TreeNode*> qu;
	qu.push(root);
	vector<vector<int>> result;
	bool flag = false;
	while(!qu.empty()){
		vector<int> level;
		int n = qu.size();
		while(n--){
			TreeNode *node = qu.front();
			qu.pop();
			level.push_back(node->val);
			if(node->left){
				qu.push(node->left);
			}
			if(node->right){
				qu.push(node->right);
			}
		}
		if(flag){
			reverse(level.begin(), level.end());
		}
		flag = !flag;
		result.push_back(level);
	}
	return result;
}
