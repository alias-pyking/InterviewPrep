#include <bits/stdc++.h>
using namespace std;
struct TreeLinkNode {
	int val;
	TreeLinkNode *left;
	TreeLinkNode *right;
	TreeLinkNode *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL){}
};
TreeLinkNode* get_next_right(TreeLinkNode* node){
	TreeLinkNode *temp = node->next;
	while(temp){
		if(temp->left) return temp->left;
		if(temp->right) return temp->right;
		temp = temp->next;
	}
	return NULL;
}

void construct_right_sibling(TreeLinkNode* root){
	if(!root) return;
	while(root){
		TreeLinkNode *current = root;
		while(current){
			if(current->left){
				if(current->right){
					current->left->next = current->right;
				} else{
					current->left->next = get_next_right(current);
				}
			}
			if(current->right){
				current->right->next = get_next_right(current);
			}
			current = current->next;
		}
		if(root->left) root = root->left;
		else if(root->right) root = root->right;
		else root = get_next_right(root);
	}
}
int main(){
}

