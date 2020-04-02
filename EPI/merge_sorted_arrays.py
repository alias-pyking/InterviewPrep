import heapq
def merge(sorted_arrays):
    min_heap = []
    result = []
    sorted_arrays_iter = [iter(x) for x in sorted_arrays]
    for i,it in enumerate(sorted_arrays_iter):
        first_element = next(it, None)
        if first_element is not None:
            heapq.heappush(min_heap,(first_element,i))
    
    while min_heap:
        smallest_entry,smallest_array_i = heapq.heappop(min_heap)
        smallest_array_iter = sorted_arrays_iter[smallest_array_i]
        result.append(smallest_entry)
        next_smallest = next(smallest_array_iter,None)
        if next_smallest is not None:
            heapq.heappush(min_heap,(next_smallest,smallest_array_i))
    return result

if __name__ == "__main__":
    test1 = [[1,2,3],[0,9,10],[6,90,200],[0,2,2]]
    print(merge(test1))
    print(list(heapq.merge(*test1)))




















