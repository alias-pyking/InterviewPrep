#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
pair<bool,int> check_balanced(TreeNode* tree){
	if(tree == NULL){
		return {true, -1};
	}
	auto left_result = check_balanced(tree->left);
	if(!left_result.first){
		return {false, 0};
	}
	auto right_result = check_balanced(tree->right);
	if(!right_result.first){
		return {false, 0};
	}
	auto balanced = abs(left_result.second - right_result.second) <= 1;
	auto height = max(left_result.second, right_result.second) + 1;
	return {balanced, height};
}
int is_balanced(TreeNode* root){
	return check_balanced(root).first;
}
int main(){
}

