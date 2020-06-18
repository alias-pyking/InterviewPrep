#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pi;
typedef vector<pair<int, int>> vpi;
typedef vector<pair<ll, ll>> vpl;
typedef vector<pair<double, double>> vpd;

#define maxvec(vec) *max_element(vec.begin(), vec.end())
#define minvec(vec) *min_element(vec.begin(), vec.end())
#define fo(i, n) for (int i = 0; i < n; i++)
#define Fo(i, n) for (int i = 1; i <= n; i++)
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define SQ(a) (a)*(a)
#define print_itrn(seq, n) fo(i, n) print(seq[i])
#define print_itr(seq, n) fo(i, n) cout << seq[i] << " ";
#define OJ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
const int N = 1e5 + 24;
const int mod = 1e9 + 7;
int n, m;
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
ListNode* removeNthFromEnd(ListNode* A, int B) {
	int n = length(A);
	if(n == 1) return NULL;
	if(B > n or n == B) return A->next;
	int pos = n - B + 1;
	ListNode *node = A;
	int i = 1;
	while(i < pos - 1){
		node = node->next;
		i++;
	}
	node->next = node->next->next;
	return A;
}
int main(){
	int t, q;
	List *list = new List();
	list->add(1);
	list->add(2);
	list->add(3);
	list->add(4);
	list->add(5);
	removeNthFromEnd((ListNode*)list->head, 5);
	list->print();
}

