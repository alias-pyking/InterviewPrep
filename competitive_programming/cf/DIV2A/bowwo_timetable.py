if __name__ == "__main__":
	num = int(str(input()), 2)
	t = 4
	ans = 0
	i = 0
	while (num >t ** i):
		ans += 1
		i += 1
	print(ans)
		