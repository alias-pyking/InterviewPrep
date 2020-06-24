#include <bits/stdc++.h>
using namespace std;
struct RandomListNode {
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 };
RandomListNode* copy_random_list(RandomListNode* L) {
	RandomListNode *current = new RandomListNode(0);
	RandomListNode *new_head = current;
	unordered_map<RandomListNode*, RandomListNode*> hash_map;
	// 1 -> 2 -> 3
	// 1 -> 3, 3 -> 1
	// 0 -> (1) -> (2) -> (3)

	// 1 -> (1)
	// 2 ->(2)
	// 3 -> (3)
	RandomListNode *node = L;
	while(node){
		RandomListNode *new_node = new RandomListNode(node->label);
		current->next = new_node;
		current = current->next;
		hash_map[node] = new_node;
		node = node->next;
	}
	node = L;
	current = new_head->next;
	while(node){
		if(node->random){
			current->random = hash_map[node->random];
		}
		current = current->next;
		node = node->next;
	}
	return new_head->next;
}

int main(){
	int t, q;

}

