# Definition for singly-linked list.
class ListNode:
   def __init__(self, x):
       self.val = x
       self.next = None

class Solution:
    # @param A : head node of linked list
    # @return the head node in the linked list
	def deleteDuplicates(self,A):
		node = A
		while node is not None:
			next = node.next
			if next is not None and next.val == node.val:
				while next is not None and next.val == node.val:
					next = next.next
			else:
				break
			node.next = next
			node = node.next
		head = node
		while node is not None:
			curr = node.next
			while curr is not None:
				next = curr.next
				if next is not None and next.val == curr.val:
					while next is not None and next.val == curr.val:
						next = next.next
				else:
					break
				curr.next = next
				curr = curr.next
			node.next = curr
			node = node.next
		return head




