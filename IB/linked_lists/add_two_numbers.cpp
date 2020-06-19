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
ListNode* addTwoNumbers(ListNode* f, ListNode* s) {
	ListNode *sum_iter = new ListNode(0);
	ListNode *sum_head = sum_iter;
	int carry = 0;
	while(f or s or carry){
		int value = carry;
		if(f) {
			value += f->val;
			f = f->next;
		}
		if(s){
			value += s->val;
			s = s->next;
		}
		sum_iter->next = new ListNode(value % 10);
		sum_iter = sum_iter->next;
		carry = value / 10;
	}
	return sum_head->next;
}

int main(){
	ListNode *f = new ListNode(9);
	f->next = new ListNode(9);
	f->next->next = new ListNode(1);
	ListNode *s = new ListNode(1);
	addTwoNumbers(f, s);
}