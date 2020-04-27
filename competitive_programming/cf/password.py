if __name__ == "__main__":
	n, k = (int(x) for x in input().split(' '))
	password = []
	characters = [chr(x) for x in range(97, 97 + k)]
	j = 0
	for i in range(0, n):
		if j >= k:
			j = 0
		password.append(characters[j])
		j += 1
	print(''.join(password))
		
		
