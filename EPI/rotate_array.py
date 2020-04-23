def rotate_array(A, i):
	i %= len(A)  # for cyclic rotation
	A[:] = A[::-1]
	A[:i] = A[:i][::-1]
	A[i:] = A[i:][::-1]

if __name__ == "__main__":
	A = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
	rotate_array(A, 5)
	print(A)
