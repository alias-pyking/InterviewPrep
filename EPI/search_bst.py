def search(tree, key):
	return (tree if not tree or tree.key == key else search(tree.left, key)\
		 if key < tree.data else search(tree.right, key)))