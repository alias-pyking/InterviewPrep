letters = str(input())
letter_set = set([x for x in letters if x not in ['{', '}',' ',',']])
print(len(letter_set))