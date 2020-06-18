#include<bits/stdc++.h>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* sorted_insert(ListNode *sorted_head, ListNode* current){
	if(sorted_head == NULL or sorted_head->val >= current->val){
		current->next = sorted_head;
		return current;
	}
	ListNode *node = sorted_head;
	// 1 -> 4 -> 5 -> 3 -> 6
	// 1 -> 3 -> 4 -> 5 -> 0  
	while(node->next and current->val > node->next->val){
		node = node->next;
	}
	current->next = node->next;
	node->next = current;
	return sorted_head;
}
ListNode* insertionSortList(ListNode* head){
	ListNode *current = head, *sorted_head = NULL;
	while(current){
		ListNode *curr_next = current->next;
		sorted_head = sorted_insert(sorted_head, current);
		current = curr_next;
	}
	return sorted_head;
}
int main(){

}