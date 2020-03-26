def reverse(word):
    word.reverse()
    def reverse_range(start, end,s):
        while start < end:
            s[start], s[end] = s[end],s[start]
            start,end = start + 1, end - 1
    start = 0
    while True:
        end = word.find(b' ', start)
        if end < 0:
            break
        reverse_range(start,end - 1,word)
        start = end + 1

    reverse_range(start, len(word) - 1,word)
