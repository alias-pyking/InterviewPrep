#include<bits/stdc++.h>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
ListNode *merge(ListNode *l2, ListNode *l1){
	ListNode *sorted_temp = new ListNode(0);
	ListNode *current_node = sorted_temp;	
	while(l1 and l2){
		if(l1->val < l2->val){
			current_node->next = l1;
			l1 = l1->next;
		} else{
			current_node->next = l2;
			l2 = l2->next;
		}
		current_node = current_node->next;
	}
	while(l1){
		current_node->next= l1;
		l1 = l1->next;
		current_node = current_node->next;
	}
	while(l2){
		current_node->next = l2;
		l2 = l2->next;
		current_node = current_node->next;
	}
	return sorted_temp->next;
}
ListNode* sortList(ListNode* head) {
	if(head == NULL or head->next == NULL){
		return head;
	}
	// 1 2 3 4
	ListNode *temp = head, *slow = head, *fast = head;
	while(fast and fast->next){
		temp = slow;
		slow = slow->next;
		fast = fast->next->next;
	}
	temp->next = NULL;
	ListNode *left_side = sortList(head);
	ListNode *right_side = sortList(slow);
	return merge(left_side, right_side);
}
int main(){

}
