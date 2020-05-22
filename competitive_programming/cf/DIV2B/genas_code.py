def check(string):
	if len(string) == 1:
		return string[0] != '1'
	if string[0] != '1':
		return True
	if any(s != '0' for s in string[1:]):
		return True
	return False
if __name__ == "__main__":
	n = int(input())
	if n == 1:
		print(input())
		exit(0)
	tanks = [str(x) for x in input().split(' ')]
	for x in tanks:
		if x == '0':
			print(0)
			exit(0)
	not_b = '1'
	for i in range(n):
		if check(tanks[i]):
			not_b = tanks[i]
			tanks[i] = '_'
			break

	result = [not_b]
	for i, x in enumerate(tanks):
		if x != '_':
			result.append('0' * (len(x) - 1))
	print(''.join(result))
	
