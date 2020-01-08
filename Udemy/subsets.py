def subset(inp,output):
    if len(inp) is 0:
        print(output)
    subset(inp[1:],output)
    subset(inp[1:],output + str(inp[0])

if __name__ == "__main__":
    pass
    n = int(input())
    output = ""
    inp = [int(x) for x in input().split()]
    print(inp)

