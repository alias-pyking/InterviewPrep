import itertools, operator
def find_biggest_n_minus_one_product(A):
	suffix_products = list(reversed(list(itertools.accumulate(reversed(A), operator.mul))))
	prefix_product, max_product = 1, float('-inf')
	for i in range(len(A)):
		suffix_product = suffix_products[i + 1] if i + 1 < len(A) else 1
		max_product = max(max_product, prefix_product * suffix_product)
		prefix_product *= A[i]
	return max_product

if __name__ == "__main__":
	A = [3, -1, 2, 4, -1, 10]
	print(find_biggest_n_minus_one_product(A))