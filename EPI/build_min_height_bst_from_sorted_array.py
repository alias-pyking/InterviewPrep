class TreeNode:
	def __init__(self, val, left, right):
		self.val = val
		self.left, self.right = left, right
def build_tree(A):
	def build_min_height_tree(start, end):
		if start >= end:
			return None
		mid = (start + end) // 2
		return TreeNode(A[mid], build_min_height_tree(start, mid), build_min_height_tree(mid + 1, end))
	return build_min_height_tree(0, len(A))
class Solution:
    # @param A : tuple of integers
    # @return the root node in the tree
    def sortedArrayToBST(self, A):
		return build_tree(A)
		
        
