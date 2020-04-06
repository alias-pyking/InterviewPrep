def find_longest_distinct_subarray(A):
	most_recent_occurence = {}
	longest_dup_free_subarray_start_idx = result = 0
	for i, a in enumerate(A):
		if a in most_recent_occurence:
			dup_idx = most_recent_occurence[a]
			if dup_idx >= longest_dup_free_subarray_start_idx:
				result = max(result, i - longest_dup_free_subarray_start_idx)
				longest_dup_free_subarray_start_idx = dup_idx + 1
		most_recent_occurence[a] = i
	return max(result, len(a) - longest_dup_free_subarray_start_idx)

if __name__ == "__main__":
	A = ['f', 's', 'f', 'e', 't', 'w', 'e', 'n', 'w', 'e']
	print(find_longest_distinct_subarray(A))