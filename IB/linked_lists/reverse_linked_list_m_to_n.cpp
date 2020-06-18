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
ListNode* reverseBetween(ListNode* head, int l, int r) {
	if(l == r) return head;
	ListNode *start = NULL, *pre_start = NULL;
	ListNode *end = NULL, *end_next = NULL;
	int i = 1;
	ListNode *current = head;
	while(current and i <= r){
		if(i < l) pre_start = current;
		if(i == l) start = current;
		if(i == r) end = current,end_next = current->next;
		current = current->next;
		i++;
	}
	// cout << start->val << ' ' << pre_start->val << '\n';
	// cout << end->val << ' ' << end_next << '\n';
	end->next = NULL;
	end = reverse(start);
	if(pre_start) pre_start->next = end;
	else head = end;
	start->next = end_next;
	return head;
}

int main(){
	List *list = new List();
	list->add(1);
	list->add(2);
	list->add(3);
	reverseBetween((ListNode *)list->head, 2, 3);
	list->print();
}