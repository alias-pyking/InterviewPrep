def k_elments_to_sum(A, t, k):
	def k_sum(i, t, k):
		if t == 0 and k == 0:
			return True
		if i >= len(A):
			return False
		if t < 0 or k < 0:
			return False
		if cache[t][k] == -1:
			case1 = k_sum(i + 1, t - A[i], k - 1)
			case2 = k_sum(i + 1, t, k)
			cache[t][k] = case1 or case2
		return cache[t][k]
	cache = [[-1]*(k+1) for _ in range(t+1)]
	return k_sum(0, t, k)

if __name__ == "__main__":
	A = [2,8,7,6,12,20,25,9]
	print(k_elments_to_sum(A,23,5))