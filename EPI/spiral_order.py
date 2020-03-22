def spiral(array):
    n = len(array)
    top = 0
    bottom = n - 1
    left = 0
    right = n - 1

    result = []
    m = 0
    while True:
        if left > right:
            break
        for i in range(left, right + 1):
            result.append(array[top][i])
        top += 1
        if top > bottom:
            break
        for i in range(top,bottom + 1):
            result.append(array[i][right])
        right -= 1
        if left > right:
            break
        for i in range(right, left - 1, -1):
            result.append(array[bottom][i])
        bottom -= 1
        if top > bottom:
            break
        for i in range(bottom,top - 1, -1):
            result.append(array[i][left])
        left += 1
    return result
tests = [[[1,2,3],[4,5,6],[7,8,9]], [[1, 2, 3, 4],[5,6,7,8], [9,10,11,12],[13,14,15,16]]]

for test in tests:
    print(spiral(test))