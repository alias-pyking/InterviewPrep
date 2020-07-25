def evaluateBrackets(brakets):
    stack = []
    for b in brakets:
        if b == '{' or b == '[' or b == '(':
            stack.append(b)
        elif b == '}' or b == ')' or b == ']':
            if not stack:
                return False
            if stack[-1] == '[' and b == ']':
                stack.pop()
                continue
            if stack[-1] == '{' and b == '}':
                stack.pop()
                continue
            if stack[-1] == '(' and b == ')':
                stack.pop()
                continue   
    return len(stack) == 0

print(evaluateBrackets('{}[]'))

