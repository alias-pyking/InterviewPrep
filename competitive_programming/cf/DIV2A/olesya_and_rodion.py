def multiply(number, a):
	result = [0]*len(number)
	for i in reversed(range(len(number))):
		result[i] = number[i] * a
		result[i - 1] += result[i] // 10
		result[i] = result[i] % 10
	return result
def get_number(n, t):
	if t == 10:
		if n == 1:
			return [-1]
		else:
			res = [1] * n
			res[-1] = 0
			return res
	else:
		res = [t] * n
		return res
if __name__ == "__main__":
	n, t = (int(x) for x in input().split(' '))
	answer = get_number(n, t)
	print(''.join([str(x) for x in answer]))


	