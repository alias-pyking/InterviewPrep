def find_longest_matchin_parens(A):
	left_parens_indices, end, max_length = [], -1, 0
	for i, c in enumerate(A):
		if c == '(':
			left_parens_indices.append(i)
		elif not left_parens_indices:
			end = i
		else:
			left_parens_indices.pop()
		start = (left_parens_indices[-1] if left_parens_indices else end)
		max_length = max(max_length, i - start)
	return max_length
