


if __name__ == "__main__":
	n = int(input())
	i = 0
	while i < n:
		word = str(input())
		if len(word) > 10:
			result = [word[0]]
			result.append(str(len(word[1:len(word) - 1])))
			result.append(word[-1])
			print(''.join(result))
		else:
			print(word)
		i += 1
		


