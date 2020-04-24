import collections, heapq
def kth_largest(A, k):
	max_heap = [-x for x in A]
	heapq.heapify(max_heap)

	for i in range(k):
		smallest = heapq.heappop(max_heap)
	return -smallest

if __name__ == "__main__":
	A = [5, 6, 2, 1, 0, 1, 2, 9]
	print(kth_largest(A,3))



