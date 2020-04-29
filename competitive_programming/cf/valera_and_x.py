def is_x(square, diagonals):
	t = square[0][0]
	if (all(square[i][j] == t for i, j in diagonals)):
		t = square[0][1]
		for i in range(len(square)):
			for j in range(len(square[0])):
				if (i, j) in diagonals:
					continue
				if square[i][j] != t or square[i][j] == square[0][0]:
					return 'NO'
		return 'YES'
	return 'NO'
					


if __name__ == "__main__":
	n = int(input())
	square = list()
	for i in range(n):
		t = str(input())
		square.append(t)
	diagonals = []
	for i in range(n):
		diagonals.append((i, i))
	j = n - 1
	for i in range(n):
		diagonals.append((i, j))
		j -= 1
	ans = is_x(square, diagonals)
	print(ans)
