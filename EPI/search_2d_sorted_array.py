def matrix_search(A,x):
    row, col = 0, len(A[0]) - 1

    while row < len(A) and col >= 0:
        if A[row][col] < x:
            row += 1
        elif A[row][col] == x:
            return (row,col)
        else:
            col -= 1
    return None
