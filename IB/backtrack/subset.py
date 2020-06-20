class Solution:
	# @param A : list of integers
	# @return a list of list of integers
	def subsets(self, A):
		if len(A) == 1:
			return [[],A[0]]
		if len(A) == 0:
			return [[]]
		res = list()
		rem_set = subsets(A[1:])
		for sub_s in rem_set:
			sub_s.sort()
			res.add(sub_s)
			res.add(sorted([A[0]] + sub_s))
		res = list(res)
		return res
