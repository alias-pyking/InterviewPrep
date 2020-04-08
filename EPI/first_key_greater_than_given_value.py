def find_first_key_greater_than(tree, value):
	subtree, first_so_far = tree, None
	while subtree:
		if subtree.data > value:
			first_so_far, subtree = subtree, subtree.left
		else:
			first_so_far, subtree = subtree, subtree.right
	return first_so_far