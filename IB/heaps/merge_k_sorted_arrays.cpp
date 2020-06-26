#include<bits/stdc++.h>
using namespace std;
struct element{
	int val, i;
	element(int val,int i){
		this->val = val;
		this->i = i;
	}
	bool operator<(const element other){
		return this->val < other.val;
	}
	bool operator>(const element other){
		return this->val > other.val;
	}
};
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
ListNode* merge_k_sorted_arrays(vector<ListNode*> sorted_lists){
	int n = sorted_lists.size();
	priority_queue<pair<int,ListNode*>, vector<pair<int,ListNode*>>, greater<pair<int,ListNode*>>> min_heap;
	for (int i = 0; i < n; i++)
	{
		ListNode *first_element = sorted_lists[i];
		if(first_element){
			min_heap.push({first_element->val, first_element});
		}
	}
	ListNode *current = new ListNode(0);
	ListNode *head = current;
	while(!min_heap.empty()){
		ListNode* smallest = min_heap.top().second;
		min_heap.pop();
		current->next = smallest;
		current = current->next;
		ListNode *next_smallest = smallest->next;
		if(next_smallest){
			min_heap.push({next_smallest->val,next_smallest});
		}
	}
	current->next = NULL;
	return head->next;
}
int main(){
	
}