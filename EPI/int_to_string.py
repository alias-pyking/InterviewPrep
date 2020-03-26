import functools
def int_to_string(x):
    res = []
    is_neg = False
    if x < 0:
        x, is_neg = -x, True
    while True:
        res.append(chr(ord('0') + x % 10))
        x //= 10
        if x == 0:
            break
    return ('-' if is_neg else '')+''.join(reversed(res))

if __name__ == '__main__':
    tests = [-123,-1,0,12,980,876,12,90]
    for test in tests:
        res = int_to_string(test)
        print(res,type(res))
    