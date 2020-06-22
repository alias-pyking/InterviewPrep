import math, itertools
def solve_sudoku(partial_assignment):
	def solve_sudoku_helper(i, j):
		if i == len(partial_assignment):
			i = 0
			j += 1
			if j == len(partial_assignment):
				return True
		if partial_assignment[i][j] != EMPTY_ENTRY:
			return solve_sudoku_helper(i + 1, j)
		def is_safe(i, j, val):
			if any(val == partial_assignment[i][k] for k in range(len(partial_assignment))):
				return False
			if any(val == partial_assignment[k][j] for k in range(len(partial_assignment))):
				return False
			region_size = int(math.sqrt(len(partial_assignment)))
			I = i // 3
			J = j // 3
			return not any(val == partial_assignment[I * region_size + a][J * region_size + b] \
						for a, b in itertools.product(range(region_size), repeat=2))
		for val in range(1, len(partial_assignment) + 1):
			if is_safe(i, j, val):
				partial_assignment[i][j] = val
				if solve_sudoku_helper(i + 1, j):
					return True
				partial_assignment[i][j] = EMPTY_ENTRY
	EMPTY_ENTRY = 0
	return solve_sudoku_helper(0,0)
class Solution:
    # @param A : list of list of chars
    # @return nothing
    def solveSudoku(self, partial_assignment):
		for i in range(len(partial_assignment)):
			for j in range(len(partial_assignment)):
				if partial_assignment[i][j] == '.':
					partial_assignment[i][j] = 0
				else:
					partial_assignment[i][j] = int(partial_assignment[i][j])
		solve_sudoku(partial_assignment)
		for i in range(len(partial_assignment)):
			for j in range(len(partial_assignment)):
				partial_assignment[i][j] = str(partial_assignment[i][j])
		return
		

