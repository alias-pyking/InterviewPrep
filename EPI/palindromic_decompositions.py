def palindromic_decompositions(input):
	def direct_decomposition(offset, partial_partition):
		if offset == len(input):
			result.append(list(partial_partition))
			return
		for i in range(offset + 1, len(input) + 1):
			prefix = input[offset:i]
			if prefix == prefix[::-1]:
				direct_decomposition(i, partial_partition + [prefix])
	result = []
	direct_decomposition(0, [])
	return result

print(palindromic_decompositions([0,2,0,4,4]))
