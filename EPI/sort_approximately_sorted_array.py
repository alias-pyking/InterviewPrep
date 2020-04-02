import heapq
import itertools
def sort_approximately_sorted_array(sequence, k):
    min_heap = []
    result = []
    for x in itertools.islice(sequence,k):
        heapq.heappush(min_heap,x)
    for x in sequence:
        smallest = heapq.heappushpop(min_heap,x)
        result.append(smallest)
    while min_heap:
        result.append(heapq.heappop(min_heap))
    return result
    