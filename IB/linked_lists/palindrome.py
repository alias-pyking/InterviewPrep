# Definition for singly-linked list.
# class ListNode:
#	def __init__(self, x):
#		self.val = x
#		self.next = None
def length(List):
	node, size = List, 0
	while node is not None:
		size += 1
		node = node.next
	return size
def reverse(node):
	curr, prev, next = node, None, None
	while curr is not None:
		next = curr.next
		curr.next = prev
		prev = curr
		curr = next
	return prev
    
class Solution:
	# @param A : head node of linked list
	# @return an integer
	def lPalin(self, A):
		n = length(A)
		mid = n / 2
		if (n % 2 != 0): mid += 1
		node = A
		i = 1
		while i <= mid:
			node = node.next
			i += 1
		node = reverse(node)
		while node is not None:
			if A.val != node.val:
				return 0
			A, node = A.next, node.next
		return 1
