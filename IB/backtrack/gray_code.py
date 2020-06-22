def genrate_gray_code(n):
	def direct_gray_code(n):
		if n == 2:
			return ['00', '01', '11', '10']
		if n == 1:
			return ['0','1']
		L1 = direct_gray_code(n - 1)
		L2 = L1[::-1]
		for i in range(len(L1)):
			L1[i] = '0' + L1[i]
		for i in range(len(L2)):
			L2[i] = '1' + L2[i]
		L = L1 + L2
		return L
	result = direct_gray_code(n)
	return result
class Solution:
    # @param A : integer
    # @return a list of integers
	def grayCode(self, A):
		res = genrate_gray_code(A)
		result = []
		for i in res:
			result.append(int(i,2))
		return result
	
# 00 01 11 10
# 000 001 011 010
# 10 11 01 00
# 110 111 101 100

sol = Solution()
print(sol.grayCode(1))	