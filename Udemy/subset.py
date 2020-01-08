sum1=16
def subset(array,s):
    if s is 0:
        return 0
    a=[]
    if array[s]<=sum1:
         a.append(array[s])
    if sum(a) is sum1:
        return 1+subset(array,s-1)
    return subset(array,s-1)



print(subset([2,4,6,10],4))

        