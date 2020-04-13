def subsets(n, k):
	def direct_combinations(offset, partial_combinations):
		if len(partial_combinations) == k:
			result.append(partial_combinations)
			return
		i = offset
		while i <= n:
			direct_combinations(i + 1, partial_combinations + [i])
			i += 1
	result = []
	direct_combinations(1, [])
	return result

print(subsets(5, 2))
