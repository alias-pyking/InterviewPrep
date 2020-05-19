import collections


def solve(word):
	dictionary = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
	freq = collections.defaultdict(int)

	if len(word) < 26:
		return - 1
	n = len(word)
	flag = False
	for i in range(n - 26 + 1):
		for j in range(i, i + 26):
			if word[j] != '?':
				freq[word[j]] += 1
		if all(freq[c] <= 1 for c in dictionary):
			for j in range(i, i + 26):
				temp = word[i: i + 26]
				if word[j] == '?':
					for c in dictionary:
						if c not in temp:
							word[j] = c
			flag = True
			break
		freq = collections.defaultdict(int)
	if flag:
		for i in range(len(word)):
			if word[i] == '?':
				word[i] = 'S'
		return ''.join(word)
	else:
		return -1
	

if __name__ == "__main__":
	word = str(input())
	word = list(word)
	print(solve(word))
	