import collections,functools

DuplicateAndMissing = collections.namedtuple('DuplicateAndMissing',('duplicate','missing'))

def find_duplicate_missing(A):
    n = len(A)
    miss_XOR_dup = functools.reduce(lambda v,i: v ^ i[0] ^ i[1],enumerate(A),0)
    # bit fiddling technique for setting the all the bits to 0 except the lsb set bit
    # 1110100 ---> 0000100
    differ_bit, miss_or_dup = miss_XOR_dup & (~(miss_XOR_dup - 1)), 0
    for i,v in enumerate(A):
        if i & differ_bit:
            miss_or_dup ^= i
        if v & differ_bit:
            miss_or_dup ^= v
    
    if miss_or_dup in A:
        return DuplicateAndMissing(miss_or_dup, miss_XOR_dup ^ miss_or_dup)
    else:
        return DuplicateAndMissing(miss_XOR_dup ^ miss_or_dup, miss_or_dup)

if __name__ == "__main__":
    tests = [
        [4,3,0,3,2],
        [6,2,0,2,1,3,5]
    ]
    for test in tests:
        missing_and_duplicate = find_duplicate_missing(test)
        print(missing_and_duplicate.duplicate, missing_and_duplicate.missing)
