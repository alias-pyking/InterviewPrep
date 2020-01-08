# ----------------------------------Knapsack() optimal soluttion using dyanmic programming memoization(cache) technique --------------------------------------------------------------------------
w=[0,2,2,3]
v=[0,6,10,12]                             
arr=[[0]*6 for i in range(4)]
def ks(pointer,capacity):
    #  base case
    if pointer is 0 or capacity is 0:
        return 0
    # if we had alread computed the value from the recursion
    #  stack then return it instead of calculating again
    if arr[pointer][capacity] is not  0:
        return arr[pointer][capacity]
    # if item is too big then skip it
    if capacity-w[pointer]<0:
        return ks(pointer-1,capacity)
    else:
        # include in the knapsack and not include in the knapsack
        # and return which has the maximum value

        # not including in the knap sack 
        temp1=ks(pointer-1,capacity)
        # including in the knap sack
        # when we add the item in the knapsack then its value is
        #  also added and capacity of the knapsack is decreased 
        # by the weigth of the item
        temp2=v[pointer]+ks(pointer-1,capacity-w[pointer])

        result=max(temp1,temp2)
        arr[pointer][capacity]=result
        return result

print(ks(3,5)) 
for i in range(4):
    for j in range(6):
        print(arr[i][j],end=" ")
    print()