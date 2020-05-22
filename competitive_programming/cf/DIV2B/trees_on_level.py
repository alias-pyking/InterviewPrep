import collections
class Node:
	def __init__(self, data):
		self.data = data
		self.left = self.right = None

class BinaryTree:
	def __init__(self, data):
		self.root = Node(data)
	def append_node(self, data, path):
		_root = self.root
		temp = path[: len(path) - 1]
		for d in temp:
			if d == 'L':
				if _root.left:
					_root = _root.left
				else:
					_root.left = Node(-1)
					_root = _root.left
			else:
				if _root.right:
					_root = _root.right
				else:
					_root.right = Node(-1)
					_root = _root.right
		if path[-1] == 'L':
			if _root.left:
				_root.left.data = data
			else:
				_root.left = Node(data)
		else:
			if _root.right:
				_root.right.data = data
			else:
				_root.right = Node(data)

def solve(tree_input):
	tree_input.pop() 
	tree_items = []
	for item in tree_input:
		temp = item[1: len(item) - 1].split(',')
		tree_items.append((int(temp[0]), temp[1]))
	del tree_input

	for item in tree_items:
		if item[1] == '':
			tree = BinaryTree(item[0])
	for item in tree_items:
		if item[1] == '':
			continue
		tree.append_node(item[0], item[1])
	root = tree.root
	queue = collections.deque()
	queue.append(root)
	result = []
	while queue:
		node = queue.popleft()
		print(node.data,end=' ')
		if node.left:
			queue.append(node.left)
		if node.right:
			queue.append(node.right)	
	print()

	
tree_input = []
while (1):
	string = input()
	if not string: break
	tree_input += string.split(' ')
	string = string.split(' ')
	if string[-1] == '()':
		flag = False
		for token in tree_input:
			if token != '()':
				temp = token[1: len(token) - 1]
				temp = temp.split(',')
				if temp[1] == '':
					solve(tree_input)
					flag = True
					tree_input = list()
		if not flag:
			print('not complete')
	
		

		