import collections
def find_smalles_subarray_covering_set(paragraph, keywords):
	keywords_to_cover = collections.Counter(keywords)
	remaining_to_cover = len(keywords)
	left = 0
	result = (-1,-1)
	for right, p in enumerate(paragraph):
		if p in keywords_to_cover:
			keywords_to_cover[p] -= 1
			if keywords_to_cover[p] >= 0:
				remaining_to_cover -= 1
		while remaining_to_cover == 0:
			if result == (-1, -1) or right - left < result[1] - result[0]:
				result = (left, right)
			p1 = paragraph[left]
			if p1 in keywords:
				keywords_to_cover[p1] += 1
				if keywords_to_cover[p1] > 0:
					remaining_to_cover += 1
			left += 1
	return paragraph[result[0]:result[1] + 1] if result != (-1, -1) else ''


class Solution:
	# @param A : string
	# @param B : string
	# @return a strings
	def minWindow(self, paragraph, keywords):
		return find_smalles_subarray_covering_set(paragraph, keywords)

sol = Solution()
print(sol.minWindow('ADOBECODEBANC','ABC'))