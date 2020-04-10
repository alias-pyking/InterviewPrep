class BstNode:
	def __init__(self, key, left, right):
		self.key = key
		self.left, self.right = left, right
def build_tree(A):
	def build_min_height_tree(start, end):
		if start >= end:
			return None
		mid = (start + end) // 2
		return BstNode(A[mid], build_min_height_tree(start, mid), build_min_height_tree(mid + 1, end))
	return build_min_height_tree(0, len(A))