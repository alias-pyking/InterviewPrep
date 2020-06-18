#include<bits/stdc++.h>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
// 1 -> 4 -> 3 -> 2 -> 5 -> 2 -> /0
// 3
// 1 -> 2 -> 2 -> 4 -> 3 -> 5 -> /0
// 2 -> 4 -> 3 -> 2 -> 5 -> 2
// 2 -> 2 -> 2 -> 4 -> 3 -> 5 -> /0 
ListNode* partition(ListNode* head, int b) {
	ListNode *less_head = new ListNode(0);
	ListNode *greater_head = new ListNode(0);
	ListNode *less = less_head, *greater = greater_head;
	while(head){
		if(head->val < b){
			less_head->next = head;
			less_head = less_head->next;
		}
		else {
			greater_head->next = head;
			greater_head = greater_head->next;
		}
		head = head->next;
	}
	greater_head->next = NULL;
	less_head->next = greater->next;
	return less->next;
}

int main(){

}