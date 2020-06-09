if __name__ == "__main__":
	mod = 1000000007
	x, y = (int(x) for x in input().split(' '))
	n = int(input())
	f = [0] * 7
	f[1] = x % mod
	f[2] = y % mod
	f[3] = (y % mod - x % mod) % mod
	f[4] = -x % mod
	f[5] = -y % mod
	f[0] = (x % mod - y % mod) % mod
	print(f[n % 6])
	

# x, y, y - x, -x, -y, x - y, x, 