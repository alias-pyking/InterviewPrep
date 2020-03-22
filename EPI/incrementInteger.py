def increment(A):
    n = len(A) 
    i = n - 1
    A[i] += 1
    if A[i]//10 != 0:
        while A[i] //10 != 0 and i > 0:
            A[i] = 0
            A[i - 1] += 1
            i -= 1
    if A[0] == 10:
        A[0] = 1
        A.append(0)

E = [9,9,9]
increment(E)
print(E)


            

