class BstNode:
	def __init__(self, data, left, right):
		self.data = data
		self.left = left
		self.right = right
def reconstruct_from_preorder(preorder_sequence):
	if not preorder_sequence:
		return None
	transistion_point = next((i for i, a in enumerate(preorder_sequence) if a > preorder_sequence[0]), len(preorder_sequence))
	return BstNode(preorder_sequence[0], reconstruct_from_preorder(preorder_sequence[1:transistion_point], \
		preorder_sequence[transistion_point:]))

def rebuild_bst_from_preorder(preorder_sequence):
	def rebuild_helper(lower_bound, upper_bound):
		if root_idx[0] == len(preorder_sequence):
			return None
		root = preorder_sequence[root_idx[0]]
		if not lower_bound <= root <= upper_bound:
			return None
		root_idx[0] += 1
		left_subtree = rebuild_helper(lower_bound, root)
		right_subtree = rebuild_helper(root, upper_bound)
		return BstNode(root, left_subtree, right_subtree)
	root_idx = [0]
	return rebuild_helper(float('-inf'), float('inf'))
