def search_cyclic(A):
    left, right = 0, len(A) - 1
    while left < right:
        mid = (left + right) // 2
        if A[mid] > A[right]:
            left = mid + 1
        else:
            right = mid
    return left

if __name__ == "__main__":
    test1 = [378, 478, 550, 631, 103, 203, 220, 234, 279, 368]
    print(search_cyclic(test1)) 