class Solution:
	# @param A : list of integers
	# @return a list of list of integers
	def permute(self, A):
		if len(A) == 0:
			return [[]]
		result = []
		rem_perms = self.permute(A[1:])
		for perm in rem_perms:
			for i in range(len(perm) + 1):
				prefix = perm[:i]
				suffix = perm[i:]
				result.append(prefix + [A[0]] + suffix)
		return result