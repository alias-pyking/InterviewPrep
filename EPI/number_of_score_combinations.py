def count_combinations(total_score, individual_scores, cache,):
	if total_score == 0:
		return 1
	if total_score < 0:
		return 0
	if not individual_score:
		return 0
	first = count_combinations(total_score - individual_score[0], individual_score)
	second = count_combinations(total_score, individual_score[1:])
	return first + second

def count_combinations_iterative(total_score, individual_scores):
	cache = [[1] + [0] * total_score for _ in range(len(individual_scores))]
	for i in range(len(individual_scores)):
		for j in range(1,total_score + 1):
			with_this_score = (cache[i][j - individual_scores[i]] if j >= individual_scores[i] else 0)
			without_this_score = (cache[i - 1][j] if i >= 1 else 0)
			cache[i][j] = with_this_score + without_this_score
	return cache[-1][-1]

if __name__ == "__main__":
	tests = [12, 14, 15, 1000]
	for test in tests:
		cache = []
		print(count_combinations_iterative(test,[2,3,7]))