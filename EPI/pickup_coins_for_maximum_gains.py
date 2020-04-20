def pickup_coins_for_maximum_gains(coins):
	def find_maximum_value(a, b):
		if a > b:
			return 0
		if maximum_value_for_range[a][b] == 0:
			maximum_value_for_range[a][b] = max(coins[a] + min(find_maximum_value(a + 2, b),find_maximum_value(a + 1, b - 1)),
												coins[b] + min(find_maximum_value(a + 1, b - 1),find_maximum_value(a, b - 2)))
		return maximum_value_for_range[a][b]
	maximum_value_for_range = [[0]*len(coins) for _ in coins]
	return find_maximum_value(0, len(coins) - 1)
if __name__ == "__main__":
	coins = [25, 5, 10, 5, 10, 5, 10, 25, 1, 25, 1, 25, 1, 25, 5, 10]
	print(pickup_coins_for_maximum_gains(coins))
