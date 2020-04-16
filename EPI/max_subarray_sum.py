def find_maximum_subarray(A):
	# kadane's algorithm
	current_sum = 0
	best_sum = 0
	for i in A:
		current_sum = max(0, current_sum + i)
		best_sum = max(best_sum, current_sum)
	return best_sum

if __name__ == "__main__":
	tests = [[1, 2, 3, -1, -10, 20, 10, -100, 100, 90, 1, -11, 90, 10, 10, 21, -1], [-2, 1, -3, 4, -1, 2, 1, -5, 4]]
	for test in tests:
		print(find_maximum_subarray(test))