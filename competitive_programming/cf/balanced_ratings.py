if __name__ == "__main__":
	n = int(input())
	a = []
	for i in range(n):
		a.append(int(input()))
	flag = 1
	for i in range(n):
		if a[i] % 2 == 0:
			print(a[i] // 2)
		else:
			print((a[i] + flag) // 2)
			flag *= -1
