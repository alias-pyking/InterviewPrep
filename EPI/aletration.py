def rearrange(A):
    for i in range(len(A) - 1):
        if i % 2 == 0 and A[i] > A[i + 1]:
            A[i],A[i+1] = A[i + 1], A[i]
        elif A[i] < A[i + 1]:
            A[i],A[i+1] = A[i + 1],A[i]
    return A
print(rearrange([1,5,9,2,19,0,8]))