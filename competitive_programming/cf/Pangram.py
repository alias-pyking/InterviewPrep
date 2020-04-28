if __name__ == "__main__":
	n = int(input())
	word = str(input())
	word = word.lower()
	word = set(word)
	if len(word) == 26:
		print('YES')
	else:
		print('NO')

