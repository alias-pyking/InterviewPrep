
def solve():
	n = int(input())
	arr = [int(x) for x in input().split(' ')]
	arr = set(arr)
	if len(arr) < 3:
		print("YES")
	if len(arr) > 3:
		print("NO")
	else:
		arr = list(arr)
		arr.sort()
		if arr[2] - arr[1] == arr[1] - arr[0]:
			print("YES")
	
	 	else: print("NO")
	return

if __name__ == "__main__":
	solve()
	