def smallest_non_constructible(A):
	A.sort()
	max_constructible = 0
	for a in A:
		if a > max_constructible + 1:
			return max_constructible + 1
		else:
			max_constructible += a
	return max_constructible + 1
