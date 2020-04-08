# node0 <= node1.data4
def lca(tree, node0, node1):
	print(tree.key)
	if tree.key > max(node0, node1):
		lca(tree.left, node0, node1)
	elif tree.key < min(node0, node1):
		lca(tree.right, node0, node1)
	else:
		return tree

