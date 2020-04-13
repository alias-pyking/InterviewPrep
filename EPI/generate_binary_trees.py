def generate_binary_trees(num_nodes):
	if num_nodes == 0:
		return [None]
	result = []
	for num_left_nodes in range(num_nodes):
		num_right_nodes = num_nodes - 1 - num_left_nodes
		left_subtrees = generate_binary_trees(num_left_nodes)
		right_subtrees = generate_binary_trees(num_right_nodes)
		result += [BstNode(0, left, right) for left in left_subtrees for right_subtees in right_subtrees]
	return result