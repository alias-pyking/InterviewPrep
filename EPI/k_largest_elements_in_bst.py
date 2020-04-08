def find_k_largest_elments(tree, k):
	def find_k_largest_elments_helper(tree,k_largest_elements):
		if tree and len(k_largest_elements) < k:
			find_k_largest_elments_helper(tree.right, k_largest_elements)
			if len(k_largest_elements) < k:
				k_largest_elements.append(tree.key)
				find_k_largest_elments_helper(tree.left, k_largest_elements)
	k_largest_elements = []
	find_k_largest_elments_helper(tree, k_largest_elements)
	return k_largest_elements

import bintrees
tree = bintrees.RBTree([(21, 'shubham'), (20, 'vish'), (19, 'tarun'), (45, 'mom'), (50, 'dad'), (25, 'Sappu')])
root = tree._root;
print(find_k_largest_elments(root,3))