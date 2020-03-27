def is_well_formed(brackets):
    stack = []
    open = ['[','{','(']
    for i in brackets:
        if i in open:
            stack.append(i)
        else:
            if len(stack) == 0:
                return False
            last = stack[-1]
            if last == '[' and i == ']':
                stack.pop()
            elif last == '{' and i == '}':
                stack.pop()
            elif last == '(' and i == ')':
                stack.pop()
            else:
                return False
    return len(stack) == 0

if __name__ == "__main__":
    tests = ['([{[]}]){}[[({})]]','([]])','[{[][]}](']
    for test in tests:
        print(is_well_formed(test))