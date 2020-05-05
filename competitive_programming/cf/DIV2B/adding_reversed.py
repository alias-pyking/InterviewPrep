def add(A,B):
	i = len(A) - 1
	j = len(B) - 1
	res = [0]*224
	k = 223
	c = 0
	while i >= 0 and j >= 0:
		res[k] += A[i] + B[j]
		res[k - 1] += res[k]//10
		res[k] = res[k]%10
		i,j,k = i - 1, j - 1, k - 1
	while i >= 0:
		res[k] += A[i]
		res[k-1] += res[k]//10
		res[k] = res[k]%10
		i -= 1
		k -= 1
	pres = list()
	for i in range(224):
		if res[i] != 0:
			break
	pres = res[i:]
	return pres
if __name__ == "__main__":
	t = int(input())
	while t > 0:
		x,y = (str(x) for x in input().split(' '))
		if len(y) > len(x):
			x,y = y,x
		for i in reversed(range(len(x))):
			if x[i] != '0':
				break
		a = x[:i + 1]
		for i in reversed(range(len(y))):
			if y[i] != '0':
				break
		b = y[:i + 1]
		a = a[::-1]
		b = b[::-1]
		a = [int(x) for x in a]
		b = [int(x) for x in b]
		res = add(a,b)
		res = res[::-1]
		for i in range(len(res)):
			if res[i] != 0:
				break
		res = res[i:]
		res =  ''.join([str(x) for x in res])
		print(res)
		t-= 1