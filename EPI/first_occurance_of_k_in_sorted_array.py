import bisect
def find_first_occurence(A,k):
    left, right, result  = 0, len(A) - 1, -1
    while left <= right:
        mid = left + (right-left) // 2
        if A[mid] > k:
            right = mid - 1
            result = mid
            right = mid - 1
        else:
            left = mid + 1
    return result

if __name__ == "__main__":
    tests = [
        [-14,-10,2,108,108,243,285,285,285,401],
        [1,2,2,2,2,5,10,12,12,12,12,12,90,90,90]
    ]
    print(find_first_occurence(tests[0],108))
    print(find_first_occurence(tests[0],285))
    print(find_first_occurence(tests[1],2))
    print(find_first_occurence(tests[1],90))
    print(bisect.bisect_right(tests[0],285))