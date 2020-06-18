#include<bits/stdc++.h>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
int length(ListNode *head){
	if(head == NULL){
		return 0;
	}
	int result = 0;
	ListNode *node = head;
	while(node !=NULL) {
		result++;
		node = node->next;
	}
	return result;
}
ListNode* reverse(ListNode* head){
	ListNode *current = head;
	ListNode *prev = NULL;
	ListNode *next;
	while(current != NULL){
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	return prev;
}

int main(){

}