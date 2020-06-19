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
ListNode* swapPairs(ListNode* head) {
	
	if(head == NULL or head->next == NULL) return head;
	int k = 2, n = length(head), i = 1;
	ListNode *current = head;
	ListNode *reverse_head = head, *prev_tail = NULL;
	ListNode *new_head = NULL;
	while(current){
		if(i % k == 0){
			ListNode *current_next = current->next;
			ListNode *prev = NULL, *rev_curr = reverse_head, *current_tail;
			current->next = NULL;
			while(rev_curr){
				ListNode *next = rev_curr->next;
				if(prev == NULL){
					current_tail = rev_curr;
				}
				rev_curr->next = prev;
				prev = rev_curr;
				rev_curr = next;
			}
			reverse_head = current_next;
			if(prev_tail){
				prev_tail->next = prev;
			} else{
				new_head = prev;
			}
			prev_tail = current_tail;
			if(n % k and i == n - 1){
				prev_tail->next = current_next;
				break;
			}	
			current = current_next;
		} else {
			current = current->next;
		}
		i++;
	}

	return new_head;
}
int main(){

}