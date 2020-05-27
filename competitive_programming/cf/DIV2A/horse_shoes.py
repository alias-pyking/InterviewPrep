s1, s2, s3, s4 = (int(c) for c in input().split(' '))
uniq = set([s1,s2,s3,s4])
print(4 - len(uniq))