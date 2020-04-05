import math
def real_sqrt(x):
    left, right = (x, 1.0) if x < 1.0 else (1.0, x)
    while not math.isclose(left,right):
        mid = 0.5 *(left + right)
        mid_squared = mid * mid
        if mid_squared > x:
            right = mid
        else:
            left = mid
    return left

if __name__ == "__main__":
    tests = [8,9,10,11,12,90,91]
    print([real_sqrt(x) for x in tests])