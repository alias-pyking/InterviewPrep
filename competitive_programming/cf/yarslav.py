import collections
if __name__ == "__main__":
	n = int(input())
	number = [int(x) for x in input().split(' ')]
	number = collections.Counter(number)
	if n % 2 == 0:
		if all(x <= n // 2 for x in number.values()):
			print("YES")
		else:
			print("NO")
	else:
		if all(x <= n // 2 + 1 for x in number.values()):
			print("YES")
		else:
			print("NO")