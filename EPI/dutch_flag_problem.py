def reorder(A,k):
    pivot = A[k]
    smaller = 0
    n = len(A)
    for i in range(n):
        if A[i] < pivot:
            A[i],A[smaller] = A[smaller], A[i]
            smaller += 1
    larger = len(A) - 1
    for i in reversed(range(n)):
        if A[i] < pivot:
            break
        elif A[i] > pivot:
            A[i],A[larger] = A[larger], A[i]
             larger -= 1

A = [0,1,2,0,2,1,1]
reorder(A,3)
print(A)
