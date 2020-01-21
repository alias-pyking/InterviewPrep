def maxSum(arr,m):
    prefix_sum = list()
    current = 0
    for i in range(0,len(arr),1):
        print(i)
        current = (arr[i] % m + current) % m
        prefix_sum.append([current,i])
    prefix_sum.sort()
    for i in range(len(prefix_sum)):
        


maxSum([3,3,9,5],7)
    
    