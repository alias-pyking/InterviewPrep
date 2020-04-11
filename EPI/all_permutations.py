def permutations(A):
	def direct_permutations(A):
		result = []
		if len(A) == 0:
			result.append([])
			return result
		first = A[0]
		rem_A = A[1:]
		rem_perms = direct_permutations(rem_A)
		for perm in rem_perms:
			for i in range(len(perm) + 1):
				prefix = perm[:i]
				suffix = perm[i:]
				result.append(prefix + [first] + suffix)
		return result
	return direct_permutations(A)

print(permutations([2,3,5,6]))