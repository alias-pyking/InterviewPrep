def mergeSort(array1,array2):
    mergedArray=[]
    a1=array1[0]
    a2=array2[0]
    if  len(array1) is 0:
        return array2
    elif len(array2) is 0:
        return array1
    i=1
    j=1
    while i<len(array1) and j <len(array2):
        print(a1,a2)
        if(a1 < a2):
            mergedArray.append(a1)
            a1=array1[i]
            i+=1
        elif(a2<a1):
            mergedArray.append(a2)
            a2=array2[j]
            j+=1
    return mergedArray
print(mergeSort([0,6,8,9],[5,7,10,12]))
