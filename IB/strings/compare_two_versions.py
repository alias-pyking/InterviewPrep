def compare(A, B):
	i = 0
	while A[i] == '0':
		i += 1
	A = A[i:]
	i = 0
	while B[i] == '0':
		i += 1
	B = B[i:]
	i = len(A) - 1
	while A[i] == '0':
		if A[i - 1] == '.':
			i -= 2
		else:
			break
	A = A[: i + 1]
	i = len(B) - 1
	while B[i] == '0':
		if B[i - 1] == '.':
			i -= 2
		else:
			break
	A = A.split('.')
	B = B.split('.')
	if len(A[0])> len(B[0]):
		return 1
	if len(B[0]) > len(A[0]):
		return -1
	if A[0] > B[0]: return 1
	elif B[0] > A[0]: return - 1
	i = 0
	while(i < len(A) and i < len(B)):
		if A[i] > B[i]:
			return 1
		elif B[i] > A[i]:
			return - 1
		i += 1
	if len(A) > len(B):
		return 1
	if len(B) > len(A):
		return -1
	return 0
class Solution:
	# @param A : string
	# @param B : string
	# @return an integer
	def compareVersion(self, A, B):
		i = 0
		while A[i] == '0':
			i += 1
		A = A[i:]
		i = 0
		while B[i] == '0':
			i += 1
		B = B[i:]
		i = len(A) - 1
		while A[i] == '0':
			if A[i - 1] == '.':
				i -= 2
			else:
				break
		A = A[: i + 1]
		i = len(B) - 1
		while B[i] == '0':
			if B[i - 1] == '.':
				i -= 2
			else:
				break
		A = A.split('.')
		B = B.split('.')
		if len(A[0])> len(B[0]):
			return 1
		if len(B[0]) > len(A[0]):
			return -1
		if A[0] > B[0]: return 1
		elif B[0] > A[0]: return - 1
		i = 0
		while(i < len(A) and i < len(B)):
			if A[i] > B[i]:
				return 1
			elif B[i] > A[i]:
				return - 1
			i += 1
		if len(A) > len(B):
			return 1
		if len(B) > len(A):
			return -1
		return 0

print(compare("01", "1"))
print(compare("1.0", "1"))
print(compare("3346237295","898195413.2.6243"))