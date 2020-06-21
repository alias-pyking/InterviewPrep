class Solution:
	# @param A : list of integers
	# @return a list of list of integers
	def subsets(self, A):
		if len(A) == 1:
			return [[],[A[0]]]
		if len(A) == 0:
			return [[]]
		res = list()
		rem_set = self.subsets(A[1:])
		for sub_s in rem_set:
			sub_s.sort()
			res.append(sub_s)
			res.append(sorted([A[0]] + sub_s))
		res = list(res)
		return res
	def subsetsWithDup(self, A):
		result = self.subsets(A)
		result = set(map(tuple, result))
		res = []
		for r in result:
			res.append(list(r))
		res.sort()
		return res
	
sol = Solution()
print(sol.subsetsWithDup([1, 2, 2]))


