#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
int isSameTree(TreeNode* tree1, TreeNode* tree2) {
	queue<TreeNode *> que1, que2;
	que1.push(tree1);
	que2.push(tree2);
	vector<int> traversal1, traversal2;
	while(!que1.empty() and !que2.empty()){
		TreeNode *node1 = que1.front();
		que1.pop();
		traversal1.push_back(node1->val);
		if(node1->left){
			que1.push(node1->left);
		}
		if(node1->right){
			que1.push(node1->right);
		}
		
	}
	while(!que2.empty()){
		TreeNode *node2 = que2.front();
		que2.pop();
		traversal2.push_back(node2->val);
		if(node2->left){
			que2.push(node2->left);
		}
		if(node2->right){
			que2.push(node2->right);
		}
	}
	if(traversal1 == traversal2){
		return 1;
	}
	return 0;
}
int main(){

}