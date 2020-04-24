def binar_search_unknown_lenght(A, k):
	p = 0
	while True:
		try:
			idx = (1 << p) - 1
			if A[idx] == k:
				return idx
			elif A[idx] > k:
				break
		except IndexError:
			break
		p += 1
	left, right = 1 << max(0, (p - 1)), (1 << p) - 2
	while left <= right:
		try:
			mid = (left + right) // 2
			if A[mid] == k:
				return mid
			elif A[mid] > k:
				right = mid - 1
			else:
				left = mid + 1
		except IndexError:
			right = mid - 1
	return - 1

			

	