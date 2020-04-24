def post_order(tree):
	def inverted_preorder():
		path_stack, result =[tree], []
		while path_stack:
			cur = path_stack.pop()
			if not cur:
				continue
			result.append(cur.data)
			path_stack.extend([cur.left, cur.right])
		return result
	return inverted_preorder()[::-1]

def inorder(tree):
	path_stack, result = [], []
	if path_stack or tree:
		if tree:
			path_stack.append(tree)
			tree = tree.left
		else:
			tree = path_stack.pop()
			result.append(tree.data)
			tree = tree.right
	return result
	

