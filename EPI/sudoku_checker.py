def is_valid_sudoku(partial_assignment):
    n = len(partial_assignment)
    def has_duplicates(block):
        block = list(filter(lambda x: x != 0, block))
        return len(block) != len(set(block))
    # check for row and column constraints 
    if any(has_duplicates([partial_assignment[i][j] for j in range(n)])
    or has_duplicates([partial_assignment[j][i] for j in range(n)])
    for i in range(n)):
        return False
    # check for region constraints 
    for i in range(n,3):
        for j in range(n,3):
            if has_duplicates([partial_assignment[x][y] for y in range(j, j + 3)] for x in range(i, i + 3)) :
                return False
    return True



 
