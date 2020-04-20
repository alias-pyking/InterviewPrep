def longest_increasing_subsequence(A):
	max_length = [1] * len(A)
	for i in range(len(A)):
		max_length[i] = max(1 + max([max_length[j] for j in range(i)
						if A[i] >= A[j]],default = 0),max_length[i])
	return max(max_length)
	
if __name__ == "__main__":
	A = [0, 8, 4, 12, 2, 10, 6, 14, 1, 9,11,100,90,10,12,0,5,2,9,10,12,321,123]
	print(longest_increasing_subsequence(A))