import heapq
def k_largest_in_binary_heap(A,k):
    if k <= 0:
        return []
    candidate_max_heap = []
    result = []
    candidate_max_heap.append((-A[0],0))
    for _ in range(k):
        largest_entry, candidate_idx = heapq.heappop(candidate_max_heap)
        result.append(-largest_entry)
        left_child_idx = 2 * candidate_idx + 1
        if left_child_idx < len(A):
            heapq.heappush(candidate_max_heap,(-A[left_child_idx],left_child_idx))
        right_child_idx = 2 * candidate_max_heap + 2
        if right_child_idx < len(A):
            heapq.heappush(candidate_max_heap,(-A[right_child_idx],right_child_idx))
    return result