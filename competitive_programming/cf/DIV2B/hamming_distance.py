if __name__ == "__main__":
	a = str(input())
	b = str(input())
	n, m = len(a), len(b)
	ones, sum = 0, 0
	diff = m - n + 1
	for i in range(diff):
		if(b[i] == '1'): ones += 1
	for i in range(n):
		if a[i] == '0': sum += ones
		else :
			sum += (diff - ones)
		if i == n - 1:
			break
		if b[i] == '1':
			ones -= 1
		if b[i + diff] == '1':
			ones += 1
	print(sum)
	

		
