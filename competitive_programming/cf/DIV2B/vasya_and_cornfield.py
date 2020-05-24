if __name__ == "__main__":
	n, d = (int(x) for x in input().split(' '))
	m = int(input())
	for i in range(m):
		x, y = (int(u) for u in input().split(' '))
		if d <= x + y <= 2*n - d and -d <= x - y <= d:
			print("YES")
		else:
			print("NO")
	