import itertools,math
def is_valid(partial_assignment,val, i, j):
	if any(val == partial_assignment[i][k] and k!= j for k in range(len(partial_assignment))):
		return False
	if any(val == partial_assignment[k][j] and k != i for k in range(len(partial_assignment))):
		return False
	region_size = int(math.sqrt(len(partial_assignment)))
	I = i // region_size
	J = j // region_size
	for a, b in itertools.product(range(region_size), repeat=2):
		row = a + I * region_size
		col = b + J * region_size
		if row == i and col == j: continue
		if val == partial_assignment[row][col]:
			return False
	return True
class Solution:
	# @param A : tuple of strings
	# @return an integer
	def isValidSudoku(self, partial_assignment):
		EMPTY_ENTRY = '.'
		for i in range(len(partial_assignment)):
			partial_assignment[i].split('.')
		for i in range(len(partial_assignment)):
			for j in range(len(partial_assignment)):
				if partial_assignment[i][j] == EMPTY_ENTRY: continue
				if not is_valid(partial_assignment, partial_assignment[i][j], i, j):
					return 0
		
		return 1
	
partial_assignment = [ "..5.....6", "....14...", ".........", ".....92..", "5....2...", ".......3.", "...54....", "3.....42.", "...27.6.."]
sol = Solution()
print(sol.isValidSudoku(partial_assignment))
					



	
