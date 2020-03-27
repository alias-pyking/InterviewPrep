def evaluate_RPN(expression):
    expression = expression.split(',')
    stack, i  = [], 0
    operators = ['+','-','*','/']
    for i in expression:
        if i not in operators:
            stack.append(int(i))
        else:
            if i == '+':
                b = stack.pop()
                a = stack.pop()
                stack.append(a + b)
            elif i == '-':
                b = stack.pop()
                a = stack.pop()
                stack.append(a - b)
            elif i == '*':
                b = stack.pop()
                a = stack.pop()
                stack.append(a * b)
            elif i == '/':
                b = stack.pop()
                a = stack.pop()
                if b == 0:
                    raise Exception('Divide by zero')
                else:
                    stack.append(a /b)
            else:
                raise Exception('Incorrect operator')
    return stack.pop()

if __name__ == "__main__":
    expressions = ['3,4,+,2,*,1,+', '1,1,+,-2,*', '-641,6,/,28,/']
    for expression in expressions:
        print(evaluate_RPN(expression))
    



