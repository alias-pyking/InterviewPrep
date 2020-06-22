# aab
def palindromic_decompositions(input):
	def direct_decomposition(offset, partial_partition):
		if offset == len(input):
			result.append(partial_partition)
			return
		for i in range(offset + 1, len(input) + 1):
			prefix = input[offset:i]
			if prefix == prefix[::-1]:
				direct_decomposition(i, partial_partition + [prefix])
		return
	result = []
	direct_decomposition(0, [])
	return result

class Solution:
	# @param A : string
	# @return a list of list of strings
	def partition(self, A):
		result = palindromic_decompositions(A)
		result.sort()
		return result

