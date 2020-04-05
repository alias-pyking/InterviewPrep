def square_root(k):
    left, right = 0, k
    while left <= right:
        mid = (left + right) // 2
        mid_sqrd = mid * mid
        if mid_sqrd <= k:
            left = mid + 1
        else:
            right = mid - 1
    return left - 1  