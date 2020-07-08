def minimum_edit_distance(A, B):
	def E(a, b):
		if a < 0:
			return b + 1
		if b < 0:
			return a + 1
		if cached_e[a][b] == -1:
			if A[a] == B[b]:
				cached_e[a][b] = E(a - 1, b - 1)
			else:
				substitue_last = E(a - 1, b - 1)
				add_last = E(a - 1, b)
				delete_last = E(a, b - 1)
				cached_e[a][b] = 1 + min(substitue_last, add_last, delete_last)
		return cached_e[a][b]
	cached_e = [[-1] * len(B) for _ in range(len(A))]
	return E(len(A) - 1, len(B) - 1)

if __name__ == "__main__":
	A = "b"
	B = "a"
	print(minimum_edit_distance(A,B))