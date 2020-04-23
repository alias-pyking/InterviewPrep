import collections
Subarray = collections.namedtuple('Subarray',('start','end'))
def largest_contiguous_subarray(A):
	result = Subarray(0, 0)
	max_length, length = 1, 1
	for i in range(1, len(A)):
		if A[i] > A[i - 1]:
			length += 1
		elif max_length < length:
			max_length = length
			result = Subarray(i - max_length, i - 1)
			length = 1
	if max_length < length:
		result = Subarray(i - length + 1, i)
	return result


if __name__ == "__main__":
	A = [2,11,3,2,1]
	print(largest_contiguous_subarray(A))
