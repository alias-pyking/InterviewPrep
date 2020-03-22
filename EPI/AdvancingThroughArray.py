def is_possible(A):
    max_reach_so_far, last_index = 0, len(A) - 1
    i = 0
    while i <= max_reach_so_far and max_reach_so_far < last_index:
        max_reach_so_far = max(max_reach_so_far, i + A[i])
        i += 1
    return max_reach_so_far >= last_index 


print(is_possible([0,1,2,3,1,0,2]))
print(is_possible([2,1,0,0,3, 4, 1, 1]))
print(is_possible([4, 5, 6, 0, 1 , 3 , 5]))
print(is_possible([3,2,2,0,1,2]))