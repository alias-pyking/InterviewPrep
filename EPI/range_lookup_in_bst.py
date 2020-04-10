import collections
Interval = collections.namedtuple('Interval',('left','right'))
def range_lookup_in_bst(tree, interval):
	def range_lookup_helper(tree):
		if not tree:
			return
		if interval.left <= tree.data <= interval.right:
			range_lookup_helper(tree.left)
			result.append(tree.data)
			range_lookup_helper(tree.right)
		if interval.left > tree.data:
			range_lookup_helper(tree.right)
		else:
			range_lookup_helper(tree.left)
	result = []
	range_lookup_helper(tree)
	return result
