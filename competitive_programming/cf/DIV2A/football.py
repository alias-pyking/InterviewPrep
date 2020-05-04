import collections
if __name__ == "__main__":
	n = int(input())
	scores = []
	for i in range(n):
		s = str(input())
		scores.append(s)
	scores = collections.Counter(scores)
	winner = ''
	max_score = float('-inf')
	for item in scores.items():
		if (item[1] > max_score):
			max_score = item[1]
			winner = item[0]
	print(winner)