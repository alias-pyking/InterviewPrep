def find_first_missing_positive(A):
	for i in range(len(A)):
		if 1 <= A[i] <= len(A) and A[A[i] - 1] != A[i]:
			A[A[i] - 1], A[i] = A[i], A[A[i] - 1]
	return next((i + 1 for i, a in enumerate(A) if a != i + 1), len(A) + 1)
if __name__ == "__main__":
	A = [3, 1, -1, 5, 6, -1]
	print(find_first_missing_positive(A))
	