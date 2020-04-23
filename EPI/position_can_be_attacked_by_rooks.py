def can_be_attacked(A):
	def fill_attacking_positions(x, y):
		for i in range(n):
			A[i][y] = 2 if A[i][y] != 0 else 0
		for j in range(m):
			A[x][j] = 2 if A[x][j] != 0 else 0
		return
	n, m = len(A), len(A[0])
	for i in range(n):
		for j in range(m):
			if A[i][j] == 0:
				fill_attacking_positions(i, j)
	for i in range(n):
		for j in range(m):
			if A[i][j] == 2:
				A[i][j] = 0			
	return

if __name__ == "__main__":
	A = [[1] * 8 for _ in range(8)]
	A[0][1] = 0
	A[6][0] = 0
	A[6][5] = 0
	A[4][3] = 0
	A[3][5] = 0
	can_be_attacked(A)
	for i in A:
		print(*i)
	