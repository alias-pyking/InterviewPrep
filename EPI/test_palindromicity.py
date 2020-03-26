def test_palindromicity(s):
    i, j = 0, len(s) - 1
    while i < j:
        while s[i].isalnum() and i < j:
            i += 1
        while s[j].isalnum() and i < j:
            j -= 1
        if s[i] != s[j]:
            return False
        i += 1
        j -= 1
    return True
 

        