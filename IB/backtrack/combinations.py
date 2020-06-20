class Solution:
    # @param A : integer
	# @param B : integer
	# @return a list of list of integers
	def combinations(self, A, k):
		if k == 1:
			res = [[x] for x in A]
			return res
			
		result = []
		for i in range(len(A) - k + 1):
			rem_comb = self.combinations(A[i + 1:], k - 1)
			for comb in rem_comb:
				result.append([A[i]] + comb)

		return result
	def combine(self, A, k):
		if A < k:
			return []
		A = list(range(1,A + 1))
		res = self.combinations(A,k)
		return res

sol  = Solution()
print(sol.combine(3,2))

		

			
