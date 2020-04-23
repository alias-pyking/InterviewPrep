def buy_and_sell_once(A):
	mini = A[0]
	maxi = A[0]
	max_profit_so_far = 0
	for i in range(len(A)):
		if A[i] < mini:
			mini, maxi = A[i], A[i]
		elif A[i] > maxi:
			maxi = A[i]
		max_profit_so_far = max(max_profit_so_far, maxi - mini)
	return max_profit_so_far

def buy_and_sell_stocks_twice(A):
	max_total_profit, min_price_so_far = 0.0, float('inf')
	first_buy_and_sell = [0] * len(A)
	for i in range(A[i]):
		max_total_profit = max(max_total_profit, A[i] - min_price_so_far)
		min_price_so_far = min(min_price_so_far, A[i])
		first_buy_and_sell[i] = max_total_profit
	max_price_so_far = float('-inf')
	for i in reversed(range(len(A))):
		max_price_so_far = max(max_price_so_far, A[i])
		max_total_profit = max(max_total_profit, max_price_so_far - A[i] + first_buy_and_sell[i - 1])
	return max_total_profit


def buy_and_sell_stocks_k_times(prices, k):
	profit = [[0] + [-1] * len(prices) for _ in range(k + 1)]
	for j in range(len(prices) + 1):
		profit[0][j] = 0
	for i in range(1, k + 1):
		for j in range(1, len(prices)):
			max_so_far = float('-inf')
			for m in range(j):
				max_so_far = max(max_so_far, prices[j] - prices[m] + profit[i - 1][m])
			profit[i][j] = max(profit[i][j - 1], max_so_far)
	return profit[k][len(prices) - 1]

if __name__ == "__main__":
	profit = buy_and_sell_stocks_k_times([100, 30, 15, 10, 8, 25, 80], 3)
	print(profit)