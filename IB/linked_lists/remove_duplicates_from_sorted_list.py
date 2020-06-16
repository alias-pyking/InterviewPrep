# Definition for singly-linked list.
# class ListNode:
#    def __init__(self, x):
#        self.val = x
#        self.next = None

class Solution:
    # @param A : head node of linked list
    # @return the head node in the linked list
    def deleteDuplicates(self, A):
        node = A
        while node is not None:
            curr = node
            while curr is not None and curr.val == node.val:
                curr = curr.next
            node.next = curr
            node = node.next
        
        return A
