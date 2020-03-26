import functools
def convert_roman(roman):
    T = {'I':1,'V':5,'X':10,'L':50,'C':100,'D':500,'M':1000}
    return functools.reduce(
        lambda val, i: val + (-T[roman[i]] if T[roman[i]] < T[roman[i + 1]] else T[roman[i]]),
        reversed(range(len(roman) - 1)),T[roman[-1]])


if __name__ == "__main__":
    tests = ['IX','VIII','X','XII','IV']
    for test in tests:
        print(convert_roman(test))