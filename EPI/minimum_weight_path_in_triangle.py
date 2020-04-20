def minimum_weight_path(trianle):
	def find_minimum_weight_path(i, j):
		if i == n:
			return 0
		if cache[i][j] == -1:
			path1 = trianle[i][j] + find_minimum_weight_path(i + 1, j)
			path2 = trianle[i][j] + find_minimum_weight_path(i + 1, j + 1)
			cache[i][j] = min(path1, path2)
		return cache[i][j]
		
	n = len(trianle)
	cache = [[-1]*len(i) for i in trianle]
	return find_minimum_weight_path(0, 0)

if __name__ == "__main__":
	triangle = [[2],
				[4, 4],
				[8, 5, 6],
				[4, 2, 6, 2],
				[1, 5, 2, 3, 4]]
	print(minimum_weight_path(triangle))