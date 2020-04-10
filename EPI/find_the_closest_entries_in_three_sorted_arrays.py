import bintrees

def find_closest_in_three_sorted_arrays(sorted_arrays):
	min_distance_so_far = float('inf')
	iters = bintrees.RBTree()
	for idx, sorted_array in enumerate(sorted_arrays):
		it = iter(sorted_array)
		first_min = next(it,None)
		if first_min is not None:
			iters.insert((first_min, idx), it)
	while True:
		min_value, min_idx = iters.min_key()
		max_value = iters.max_key()[0]
		min_distance_so_far = min(max_value - min_value, min_distance_so_far)
		it = iters.pop_min()[1]
		next_min = next(it, None)
		if next_min is None:
			return min_distance_so_far
		iters.insert((next_min, min_idx), it)

if __name__ == "__main__":
	sorted_arrays = [[5, 10, 15], [3, 6, 9, 12, 15], [8, 16, 24]]
	print(find_closest_in_three_sorted_arrays(sorted_arrays))