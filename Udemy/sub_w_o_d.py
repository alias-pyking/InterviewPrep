def lcs(a,b,n,m):
    if n is 0 or m is 0:
        result=0
    elif a[n-1] is b[n-1] :
        result=1+lcs(a,b,n-1,m-1)
    else:
        temp1=lcs(a,b,n,m-1)
        temp2=lcs(a,b,n-1,m)
        result=max(temp1,temp2)
    return result
a='shubham'
b='shubham'
n=len(a)
print(lcs(a,b,n,n))