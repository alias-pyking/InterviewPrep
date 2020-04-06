def longest_contained_range(A):
	unprocessed_entries = set(A):
	result = float('-inf')
	while unprocessed_entries:
		a = unprocessed_entries.pop()
		lower_bound = a - 1
		while lower_bound in unprocessed_entries:
			unprocessed_entries.remove(lower_bound)
			lower_bound -= 1
		upper_bound = a + 1
		while upper_bound in unprocessed_entries:
			unprocessed_entries.remove(upper_bound)
			upper_bound += 1
			result = max(result, upper_bound - lower_bound - 1)
	return result
	
		