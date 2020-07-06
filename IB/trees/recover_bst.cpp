#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
TreeNode *previous = NULL, *first, *second;
void inorder(TreeNode* root){
	if(root == NULL) return;
	inorder(root->left);
	if(previous != NULL){
		if(previous->val > root->val){
			if(first == NULL){
				first = previous;
			}
			second = root;
		}
	}
	previous = root; 
	inorder(root->right);
}

int main(){
	int t, q;
}

