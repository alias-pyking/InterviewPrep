def next_permutation(perm):
    n = len(perm)
    i = n - 1
    min_index = i
    while i > 0:
        if perm[i] < perm[min_index]:
            min_index = i
        if perm[i - 1] < perm[i]:
            perm[i - 1], perm[min_index] = perm[min_index], perm[i - 1]
            perm[i:] = reversed(perm[i:])
            return perm
        i -= 1
    return []

tests = [
    [1,4,5],
    [1,0,3,2],
    [1,5,3],
    [9,2,1],
    [1,2,5]
]
for test in tests:
    print(next_permutation(test))
     


