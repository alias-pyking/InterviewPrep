if __name__ == '__main__':
    s = str(input())
    clock = [chr(c) for c in range(97, 97 + 26)]
    idx = 0
    rotatinos = 0
    for c in s:
        t1 = 0
        t2 = 0
        t = idx
        for i in range(idx, idx + 26):
            if clock[i % 26] == c:
                break
            t1 += 1
        for j in range(idx, idx - 26, -1):
            if(abs(j) >= 26):
                j = j + 26
            if clock[j] == c:
                break
            t2 += 1

        idx = i % 26 if t1 < t2 else j
        rotatinos += min(t1, t2)
    print(rotatinos)


        
    
