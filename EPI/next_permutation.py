def next_permutation(perm):
    n = len(perm)
    i = n - 1
    min_index = i
    while i > 0:
        if perm[i] < perm[min_index]:
            min_index = i
        if perm[i - 1] < perm[i]:
            perm[i - 1], perm[min_index] = perm[min_index], perm[i - 1]
            perm[i:] = sorted(perm[i:])
            return perm
        i -= 1
    return []
# 1 2 3 4 
# 1 2 4
tests = [
    [1,2,3,4,5,6,7,8,9,10,11],
    [1,0,3,2],
    [1,5,3],
    [9,2,1],
    [2,3,1]
]
for test in tests:
    print(next_permutation(test))
     


