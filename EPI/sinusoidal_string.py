def  sinusoidal_string(string):
    res = []
    for i in range(1,len(string),4):
        res.append(string[i])
    for i in range(0,len(string),2):
        res.append(string[i])
    for i in range(3,len(string),4):
        res.append(string[i])
    return ''.join(res)
# Pythonic_solution
def sinusoidal_string_pythonic(string):
    return string[1::4] + string[::2] + string[3::4]

if __name__ == "__main__":
    tests = ['Hello_World!','Shubham_Kumar']
    for test in tests:
        print(sinusoidal_string(test))
        print(sinusoidal_string_pythonic(test))