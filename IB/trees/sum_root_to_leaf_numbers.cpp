#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
int get_number(vector<int> number){
	int n = number.size();
	int num = 0;
	for (int i = 0; i < n; i++){
		num *= 10 % 1003;
		num += number[i];
		num %= 1003;
	}
	return num;
}
void sum_numbers_helper(TreeNode* root, int &sum, vector<int> number){
	if(not root){
		return;
	}
	if(not root->left and not root->right){
		number.push_back(root->val);
		int num = get_number(number);
		sum += num % 1003;
		sum %= 1003;
	}
	number.push_back(root->val);
	sum_numbers_helper(root->left, sum,number);
	sum_numbers_helper(root->right, sum,number);
	number.pop_back();
}
int sum_numbers(TreeNode* root){
	int sum = 0;
	vector<int> number;
	sum_numbers_helper(root, sum, number);
	return sum % 1003;
}
int main(){

}