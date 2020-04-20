import collections
Item = collections.namedtuple('Item',('weight','value'))

def knapsack(items, C):
	def ks(available_capacity, k):
		if k < 0:
			return 0
		if available_capacity < items[k].weight:
			return ks(available_capacity, k - 1)

		if cached_max[k][available_capacity] == -1:
			t1 = items[k].value + ks(available_capacity - items[k].weight, k - 1)
			t2 = ks(available_capacity, k - 1)
			cached_max[k][available_capacity] = max(t1, t2)

		return cached_max[k][available_capacity]
	cached_max = [[-1] *(C + 1) for _ in items]
	return ks(C, len(items) - 1)

if __name__ == "__main__":
	print(knapsack([Item(5,60),Item(3,50), Item(4,70),Item(2,30)], 5))

	
