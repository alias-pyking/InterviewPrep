
def C(n, k):
	def fact(x):
		r = 1
		for i in range(1, x + 1):
			r *= i
		return r
	up = 1
	lower = fact(n - k)
	for i in range(n, k, -1):
		up *= i
	res = up // lower
	return res
if __name__ == "__main__":
	n, m, t = (int(x) for x in input().split())
	nb, ng = 0, 0
	ans = 0
	for b in range(4, n + 1):
		g = t - b

		if g < 1 or g > m:
			continue
		nb, ng = C(n, b), C(m, g)
		ans += nb*ng
	print(ans)
		