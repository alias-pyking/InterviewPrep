import collections
def can_form_palindrom(s):
    return sum(v%2 for v in collections.Counter(s).values()) <= 1

if __name__ == "__main__":
    tests = ['edifeid','moron','elivis']
    print([can_form_palindrom(test) for test in tests])