def count_ways(n,m):
	def count_ways_helper(x, y):
		if x == y == 0:
			return 1
		if no_of_ways[x][y] == 0:
			ways_to_top = 0 if x == 0 else count_ways_helper(x - 1, y)
			ways_to_left = 0 if y == 0 else count_ways_helper(x, y - 1)
			no_of_ways[x][y] = ways_to_left + ways_to_top
		return no_of_ways[x][y]
	no_of_ways = [[0] * m for _ in range(n)]
	return count_ways_helper(n - 1, m - 1)
if __name__ == "__main__":
	print(count_ways(5, 5))
	