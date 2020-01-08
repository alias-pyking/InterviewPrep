
arr=[[0]*4 for i in range(4)]
def lcs(P,Q,n,m):
    if arr[n][m]is not 0:
        return arr[n][m]
    if n is 0 or m is 0:
        result=0
    elif P[n-1] is Q[m-1]:
        result=1+lcs(P,Q,n-1,m-1)
    else:
        temp1=lcs(P,Q,n-1,m)
        temp2=lcs(P,Q,n,m-1)
        result=max(temp1,temp2)
        arr[n][m]=result
    return result
print(lcs("aaa","aaa",3,3))
