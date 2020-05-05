if __name__ == "__main__":
	n = int(input())
	word = str(input())
	decoding = str()
	flag = True
	decoding = word[0]
	if len(word) % 2 != 0:
		for i in range(1, n):
			if flag:
				decoding = word[i] + decoding
				flag = False
			else:
				decoding = decoding + word[i]
				flag = True
		print(decoding)
	else:
		for i in range(1, n):
			if flag:
				decoding = decoding + word[i]
				flag = False
			else:
				decoding = word[i] + decoding
				flag = True
		print(decoding)
			
			
		