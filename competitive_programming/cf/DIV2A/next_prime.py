if __name__ == '__main__':
	n,m = (int(x) for x in input().split(' '))
	N = 50
	is_prime = [False, False] + [True] * (N - 1)
	for p in range(2,N + 1):
		if is_prime[p]:
			for i in range(p + p,N + 1,p):
				is_prime[i] = False
	ans = "YES" if is_prime[m] else "NO"
	for i in range(n + 1,m):
		if is_prime[i]:
			ans = "NO"
			break
	print(ans)