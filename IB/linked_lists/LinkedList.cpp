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
int main(){
	List *list = new List();
	list->add(10);
	list->add(20);
	list->add(45);
	list->add(50);
	list->add(100);
	list->print();
	list->reverse();
	list->print();
	delete list;
	return 0;
}