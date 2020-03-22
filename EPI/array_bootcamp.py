import copy
import bisect

A = [1,3,4,5,7,9,10,12]
print(bisect.bisect(A,5))
print(bisect.bisect(A,2))
print(bisect.bisect_left(A,5))
print(bisect.bisect_left(A,6))
print(bisect.bisect_right(A,9))
print(bisect.bisect_right(A,8))