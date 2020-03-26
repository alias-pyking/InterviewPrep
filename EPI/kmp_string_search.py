def kmp_search(text,substring):
    pattern = [0]*len(substring)
    n, m = len(text), len(substring)
    i, j = 1, 0
    while i < m:
        if substring[i] == substring[j]:
            pattern[i] = j + 1
            i, j = i + 1, j + 1
        else:
            if j - 1 >= 0:
                j = pattern[j - 1]
            else:
                j = 0
            if substring[i] == substring[j]:
                pattern[i] = j + 1
                i, j = i + 1, j + 1
            else:
                pattern[i] = 0
                i += 1
    i = 0
    j = 0
    while i < n and j < m:
        if text[i] == substring[j]:
            i += 1
            j += 1
            if j == m:
                return (i - j , i )
        else:
            if j - 1 >= 0:
                j = pattern[j - 1]
            else:
                i += 1
    return (-1,-1)

    

if __name__ == "__main__":
    tests = [("abxabcabcaby","abcaby")]
    for test in tests:
        i,j = kmp_search(test[0],test[1])
        print(i,j)
        print(test[0][i:j])

