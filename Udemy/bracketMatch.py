# bracket match codechef problem
def match(bracket):
    current_depth=0
    depth=0
    First_occurence=0
    curr_length=0
    max_length=0
    for i in range(1,len(bracket)):
        if bracket[i] is 1:
            current_depth+=1
            curr_length+=1
            if depth<current_depth:
                depth=current_depth
                First_occurence=i
                
        elif bracket[i] is 2:
            current_depth-=1
            curr_length+=1
            if current_depth is 0:
                if max_length<curr_length:
                    max_length=curr_length
                    curr_length=0
                curr_length=0
    print('{} {} {}'.format(depth,First_occurence,max_length))


bracket=[0,1,2,1,1,2,2,1,2,1,1,2,1,2,2,1,1,2,1,2,2]
match(bracket)