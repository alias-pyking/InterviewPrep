def valid_placements_exists(A, B):
	# Checks if B can be placed in front of A
	return all(a > b for a,b in zip(sorted(A),sorted(B))))