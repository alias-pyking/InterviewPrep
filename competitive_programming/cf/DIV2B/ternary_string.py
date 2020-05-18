if __name__ == "__main__":
	t = int(input())
	while (t > 0):
		string = str(input())
		hash_pat = {}
		pattern = '123'
		n = len(string)
		c = 0
		ans = float('inf')
		for i,s in enumerate(string):
			if s in pattern:
				if s in hash_pat:
					hash_pat[s] += 1
				else:
					c += 1
					hash_pat[s] = 1
			if c == 3:
				seen = set()
				j = i
				while j >= 0:
					if string[j] in pattern and string[j] not in seen:
						c -= 1
						seen.add(string[j])
					if c == 0:
						break
					j -= 1
				ans = min(ans, i - j + 1)
		if ans == float('inf'):
			print(0)
		else:
			print(ans)
		t -= 1


				



	