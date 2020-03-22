
def delete_duplicates_from_sorted(A):
    n = len(A)
    t = 1
    for i in range(1, n):
        if A[t - 1] != A[i]:
            A[t] = A[i]
            t += 1
    A[t:] = [0 for i in range(t,n)]


if __name__ == "__main__":
    A = [1,2,2,3,4,5,6,7,7,8,9,9,9]
    B = [2, 3, 5, 5, 7, 11, 11, 11, 13]
    delete_duplicates_from_sorted(A)  
    delete_duplicates_from_sorted(B)
    print(B)
    print(A)
