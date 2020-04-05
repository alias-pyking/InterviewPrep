def search_for_entry_equal_index(A):
    left, right = 0, len(A) - 1
    while left <= right:
        mid = left + (right - left) // 2
        if A[mid] > mid:
            right = mid - 1
        elif A[mid] == mid:
            return mid
        else:
            left = mid + 1
    return -1

if __name__ == "__main__":
    test1 = [-1,0,6,9,10]
    print(search_for_entry_equal_index(test1))