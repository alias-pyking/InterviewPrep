def ss_decode_col_id(col):
    def get_int(c):
        return ord(c) - ord('A') + 1
    res = 0
    for i in range(len(col)):
        res += get_int(col[i]) * 26**i
    
    return res

if __name__ == "__main__":
    tests = ['AA','A','Z','B','AB','ZZZ','ZZ']
    for test in tests:
        print(ss_decode_col_id(test))

    
