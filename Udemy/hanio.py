#--------------------------------------------------------------------------Tower of Hanoi----------------------------------------------------------------------------------
origin=[1,2,3,4,5,6,7,8,9,10]
buffer=[0]*10
des=[]
def move(n,origin,des,buffer):
    if n is 0:
        return 
    # move the n-1 disks to the buffer
    # using buffer as des
    # understand it only using 1,2 in the 
    # towers remaining recursion will do 
    move(n-1,origin,buffer,des)
    # move the top now at origin to the des
    moveTop(origin,des)
    # move the disk at buffer to dest. using 
    # buffer as origin and same des
    move(n-1,buffer,des,origin)
def moveTop(origin,des):
     top=origin.pop()
     des.append(top)
    
move(10,origin,des,buffer)
print(des)
