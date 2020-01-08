def print_subset(inp,output):
    if len(inp) is 0:
        for x in output:
            print(x,end='')
        print()
    else:
        print_subset(inp[1:],output)
        print_subset(inp[1:],output + str(inp[0])+" ")
n = int(input())
output = ""
inp = [int(x) for x in input().split()]
print_subset(inp,output)

