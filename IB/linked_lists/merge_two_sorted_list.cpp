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
#define print(var) cout << var << "\n";
#define print_itrn(seq, n) fo(i, n) print(seq[i])
#define print_itr(seq, n) fo(i, n) cout << seq[i] << " ";
#define OJ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
const int N = 1e5 + 24;
const int mod = 1e9 + 7;
int n, m;
struct ListNode{
		int val;
		ListNode *next;
		ListNode(){

		}
		ListNode(int val, ListNode *next = NULL){
			this->val = val;
			this->next = next;
		}
};
class List{
	struct ListNode{
		int val;
		ListNode *next;
		ListNode(){

		}
		ListNode(int val, ListNode *next = NULL){
			this->val = val;
			this->next = next;
		}
	};
		

	public:
		ListNode *head = NULL;
		ListNode *tail = NULL;
		void add(int val){
			if(this->head == NULL){
				this->head = new ListNode(val);
				this->tail = head;
			} else {
				ListNode* new_node = new ListNode(val);
				this->tail->next = new_node;
				this->tail = new_node;
			}
		}
	
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
	List *list = new List();
	while(l1 != NULL and l2 != NULL){
		if(l1 -> val < l2-> val){
			list->add(l1->val);
			l1 = l1->next;
		} else {
			list->add(l2->val);
			l2 = l2->next;
		}
	}
	while (l1 != NULL){
		list->add(l1->val);
		l1 = l1->next;
	}
	while(l2 != NULL){
		list->add(l1->val);
		l2 = l2->next;
	}
	return (ListNode*)list->head;
}

int main(){
	int t, q;
	cin >> n;
}

