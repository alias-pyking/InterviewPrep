def permute(A,P):
    for i in range(len(P)):
        A[P[i]],A[i] = A[i],A[P[i]]

A = ['a','b','c','d']
P = [3, 2, 1, 0]
permute(A,P)
print(A)