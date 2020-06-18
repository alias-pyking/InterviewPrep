#include<bits/stdc++.h>
using namespace std;
class List{
	struct Node{
		int val;
		Node *next;
		Node(){

		}
		Node(int val, Node *next = NULL){
			this->val = val;
			this->next = next;
		}
	};
	
		

	public:
		Node *head = NULL;	
		int length(){
			if(this->head == NULL){
				return 0;
			}
			int result = 1;
			Node *node = head;
			while(node !=NULL) {
				result++;
				node = node->next;
			}
			return result;
		}
		void add(int val){
			if(this->head == NULL){
				this->head = new Node(val);
			} else {
				Node *node = this->head;
				while(node->next != NULL){
					node = node->next;
				}
				node->next = new Node(val);
			}
		}
		// 1 2 3 4 5 6 7 8 9
		void reverse(){
			Node *current = head;
			Node *prev = NULL;
			Node *next;
			while(current != NULL){
				next = current->next;
				current->next = prev;
				prev = current;
				current = next;
			}
			this->head = prev;
		}
		void print(){
			Node *node = head;
			while(node != NULL){
				cout << node->val << ' ';
				node = node->next;
			}
			cout << '\n';
		}
	
};
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
ListNode* reorderList(ListNode* head) {
	int n = length(head);
	int mid = n / 2 + 1, i = 1;
	if(n % 2) mid++;
	// 1 2 3 4
	ListNode *node = head, *mid_node = NULL,*pre_mid = NULL;
	while(i <= mid and node){
		if(i < mid) pre_mid = node;
		if(i == mid) mid_node = node;
		node = node->next;
		i++;
	}
	node = reverse(mid_node);
	ListNode *_head = head;
	pre_mid->next = NULL;
	while(node){
		ListNode *next = _head->next;
		_head->next = node;
		ListNode *temp = node->next;
		node->next = next;
		node = temp;
		_head = next;
	}
	return head;
}
int main(){
	List *list = new List();
	list->add(1);
	list->add(2);
	list->add(3);
	list->add(4);
	list->print();
	reorderList((ListNode*)list->head);
	list->print();
}