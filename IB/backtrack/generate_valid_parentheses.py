def is_valid(string):
	if string[0] == ')':
		return False
	stack = list()
	for i in string:
		if i == '(':
			stack.append(i)
		else:
			if not stack:
				return False
			stack.pop()
	return not stack
def generate_parenthesis(n):
	def generate_parenthesis_helper(partial):
		if len(partial) == n:
			if is_valid(partial):
				result.append(partial)
			return
		generate_parenthesis_helper(partial + '(')
		generate_parenthesis_helper(partial +')')
	result = []
	generate_parenthesis_helper('');
	return result
class Solution:
	# @param A : integer
	# @return a list of strings

	def generateParenthesis(self, A):
		result = generate_parenthesis(2*A)
		return result


sol = Solution()
print(sol.generateParenthesis(3))
		
