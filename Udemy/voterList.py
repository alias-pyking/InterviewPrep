def function(a,b,c):
    x=len(a)
    y=len(b)
    z=len(c)
    m=max(x,y,z)
    myhash={}
    for i in range(x):#O(len(a))
        myhash[a[i]]=1
    for i in range(y):#o(len(b))
        if b[i] in myhash:# o(1)
            myhash[b[i]]+=1
        else:
            myhash[b[i]]=1
    for i in range(z):#o(len(c))
        if c[i] in myhash:
            myhash[c[i]]+=1
        else:
            myhash[c[i]]=1
    for i,j in sorted(myhash.items()):
        if j>=2:
            print(i)

