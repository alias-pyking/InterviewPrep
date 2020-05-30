import collections
if __name__ == "__main__":
	s = list(input())
	t = list(input())
	freq_t = collections.Counter(t)
	ans1, ans2 = 0,0
	for i, c in enumerate(s):
		if freq_t[c] > 0:
			ans1 += 1
			s[i] = '-'
			freq_t[c] -= 1
	for c in s:
		if c == '-':
			continue
		if c.islower():
			c = c.upper()
		else:
			c = c.lower()
		if freq_t[c] > 0:
			ans2 += 1
			freq_t[c] -= 1
	print(ans1, ans2)


