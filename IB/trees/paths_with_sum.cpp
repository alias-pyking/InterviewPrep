#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
vector<vector<int>> result;
void generate_paths(TreeNode* tree, vector<int> current_path, int current_sum, int sum){
	if(!tree) return;
	if(!tree->left and !tree->right){
		current_sum = current_sum + tree->val;
		if(current_sum == sum){
			current_path.push_back(tree->val);
			
			result.push_back(current_path);
		}
		return;
	}
	current_path.push_back(tree->val);
	generate_paths(tree->left, current_path, current_sum + tree->val, sum);
	generate_paths(tree->right, current_path, current_sum + tree->val, sum);
	current_path.pop_back();
}
vector<vector<int>> path_sum(TreeNode* tree, int sum){
	vector<int> current_path;
	generate_paths(tree, current_path, 0, sum);
	return result;
	
}
int main(){
	TreeNode *root = new TreeNode(1000);
	root->left = new TreeNode(2000);
	root->left->left = new TreeNode(-3001);
	vector<vector<int>> result = path_sum(root, -1);
	for(auto v: result){
		for(auto u: v){
			cout << u << ' ';
		}
		cout << '\n';
	}
}