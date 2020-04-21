def maximum_water_trapped(A):
	i, j = 0, len(A) - 1
	max_water, start, end= float('-inf'), -1, -1
	while i < j:
		cur_max_water_trapped = min(A[i], A[j]) * (j - i)
		if cur_max_water_trapped > max_water:
			max_water = cur_max_water_trapped
			start = i
			end = j
		if A[i] < A[j]:
			i += 1
		else:
			j -= 1
	return (start,end)

if __name__ == "__main__":
	A = [1, 2, 1, 3, 4, 4, 5, 6, 2, 1, 3, 1, 3, 2, 1, 2, 4, 1]
	print(maximum_water_trapped(A))
	