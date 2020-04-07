class ListNode:
	def __init__(self, data, next):
		self.data = data
		self.next = None
def stable_sort(L):
	if not L or L.next:
		return L
	pre_slow, slow, fast = None, L, L
	while fast and fast.next:
		pre_slow = slow
		slow, fast = slow.next, fast.next.next
	pre_slow.next = None
	return merge_two_sorted_lists(stable_sort(L), stable_sort(slow))

def merge_two_sorted_lists(L1, L2):
	dummy_head = tail = ListNode()
	while L1 and L2:
		if L1.data < L2.data:
			tail.next, L1 = L1, L1.next
		else:
			tail.next, L2 = L2, L2.next
		tail = tail.next
	return dummy_head.next
		
	
