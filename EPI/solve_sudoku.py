import math,itertools
def solve_sudoku(partial_assignment):
	def solve_partial_soduku(i, j):
		if i == len(partial_assignment):
			i = 0
			j += 1
			if j == len(partial_assignment):
				return True
		if partial_assignment[i][j] != EMPYT_ENTRY:
			return solve_partial_soduku(i + 1, j)

		def valid_to_add(i, j, val):
			if any(val == partial_assignment[i][k] for k in range(len(partial_assignment))):
				return False
			if val in partial_assignment[i]:
				return False
			region_size = int(math.sqrt(len(partial_assignment)))
			I = i // region_size
			J = j // region_size
			return not any(val == partial_assignment[I * region_size +  a][b + region_size* J] \
				for a, b in itertools.product(range(region_size), repeat=2))
		
		for val in range(1, len(partial_assignment) + 1):
			if valid_to_add(i, j, val):
				partial_assignment[i][j] = val
					if solve_partial_soduku(i + 1, j):
							return True
				partial_assignment[i][j] = EMPYT_ENTRY
		return False		
	EMPYT_ENTRY = 0
	return solve_partial_soduku(0,0)
	
