
if __name__ == "__main__":
	s = str(input())
	n = len(s)
	vec = list()
	for i in range(n - 3):
		if s[i] == 'b' and s[i + 1] == 'e' and s[i + 2] == 'a' and s[i + 3] == 'r':
			vec.append(i + 1)
	size = len(vec)
	x = 1
	ans = 0
	for i in range(size):
		y = n - vec[i] - 2
		if i:
			x = vec[i - 1] + 1
		x = vec[i] - x + 1
		ans += (x * y)
	print(ans)

# bearaabearc
# 11 - 1 = 10 - 2 = 8