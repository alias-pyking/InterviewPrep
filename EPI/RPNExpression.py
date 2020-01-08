def EvaluateRPN(expression):
    intermediate_results = []
    DELEMETER = ','
    OPERATORS = {'+': lambda y, x: x + y,
                 '-': lambda y, x: x - y,
                  '*': lambda y, x: y * x,
                  '/': lambda y, x: x // y}
    for token in expression.split(DELEMETER):
        if token in OPERATORS:
            intermediate_results.append(OPERATORS[token](intermediate_results.pop(), intermediate_results.pop()))
        else:
            intermediate_results.append(int(token))
    return intermediate_results[-1]


print(EvaluateRPN('3,4,+,2,*,1,+'))
