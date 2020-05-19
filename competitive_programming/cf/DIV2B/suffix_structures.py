import collections

def is_subsequence(s,t):
	n, m = len(s), len(t)
	i, j = 0, 0
	while i < n and j < m:
		if s[i] == t[j]:
			j += 1
		i += 1
	return j == m

def solve(s,t):
	n = len(s)
	m = len(t)
	freqt = collections.defaultdict(int)
	for c in t:
		freqt[c] += 1
	freqs = collections.defaultdict(int)
	if n < m:
		return 'need tree'
	for c in s:
		if c in t:
			freqs[c] += 1
	if all(freqs[c] >= freqt[c] for c in t):
		if n == m:
			return 'array'
		elif is_subsequence(s,t):
			return 'automaton'
		else:
			return 'both'
	return 'need tree'
if __name__ == '__main__':
	s = str(input())
	t = str(input())
	print(solve(s,t))
	# print(is_subsequence(s,t))
	
			
		
