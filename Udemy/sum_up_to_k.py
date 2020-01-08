def subset(arr):
    n = len(arr)
    if ( n <= 0):
        output = [[]]
        return output
    output = subset(arr[:n-1])
    outputlen = len(output)
    for i in range(0,outputlen):
        output.append(output[i].copy())
        output[outputlen + i].append(arr[n - 1])
    return output
n = int(input())
arr = list(int(i) for i in input().strip().split(' '))
k = int(input())
output = subset(arr)
sum_array = [[]]
for a in output:
    if sum(a) == k:
        sum_array.append(a)
for i in sum_array:
    print(*i,end=' ')
    print()


