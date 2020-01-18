from collections import  Counter
def isValid(s):
    cnt = Counter(s)
    print(cnt.values)
    if len(cnt.values()) == 1:
        return "YES"
    elif len(set(cnt.values())) > 2:
        return "NO"
    else :
        for i in cnt.keys():
            cnt[i] -= 1
            if len(cnt.values()) == 1:
                return 'YES'
            else:
                cnt[i] += 1
    return 'NO'
    

