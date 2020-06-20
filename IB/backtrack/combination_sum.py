class Solution:
	# @param A : list of integers
	# @return a list of list of integers
	def permute(self, A, k):
		if len(A) == 0:
			return [[]]
		result = []
		rem_perms = self.permute(A[1:], k)
		for perm in rem_perms:
			if sum(perm) == k:
				result.append(sorted(perm))
			for i in range(len(perm) + 1):
				prefix = perm[:i]
				suffix = perm[i:]
				temp = prefix + [A[0]] + suffix
				if sum(temp) == k:
					result.append(temp)
		return result

sol = Solution()
print(sol.permute([2,3,6,7], 7))