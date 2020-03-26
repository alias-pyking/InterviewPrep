def run_length_encoding(s):
    i, n = 0,len(s)
    res = []
    while i < n:
        c = s[i]
        j = i + 1
        cnt = 1
        while j < n and  s[j] == c:
            j += 1
            cnt += 1
        i = j
        res.append('{}{}'.format(cnt,c))
    return ''.join(res)

def run_length_decoding(s):
    n, res = len(s), []
    for i in range(0,n,2):
        cnt = int(s[i])
        while cnt > 0:
            res.append(s[i + 1])
            cnt -= 1
    return ''.join(res)


if __name__ == "__main__":
    tests = ['aaacbda','aaadadfsacaasdadfd','aaabcccdddeeff']
    for test in tests:
        encoded = run_length_encoding(test)
        print(encoded)
        print(run_length_decoding(encoded))

