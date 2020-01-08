def print_subset(inp,output,k):
    if len(inp) is 0:
        sum = 0
        for x in output:
            if x is " ":
                continue
            else:
                sum += int(x)
        if sum == k:
            for x in output:
                print(x,end='')
            print()
    else:
        print_subset(inp[1:],output,k)
        print_subset(inp[1:],output + str(inp[0])+" ",k)
n = int(input())
output = ""
inp = [int(x) for x in input().split()]
print_subset(inp,output,6)

