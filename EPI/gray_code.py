def gray_codes(num_bits):
	def direct_gray_code(history):
		def differ_by_one_bit(x, y):
			bit_difference = x ^ y
			return bit_difference and not bit_difference & (bit_difference - 1)
		if len(result) == 1 << num_bits:
			return differ_by_one_bit(result[0], result[-1])
		for i in range(num_bits):
			previous_code = result[-1]
			next_candidate_code = previous_code ^ (i << i)
			if next_candidate_code not in history:
				history.add(next_candidate_code)
				result.append(next_candidate_code)
				if direct_gray_code(history):
					return True
				history.remove(next_candidate_code)
				del result[-1]
		return False
	result = [0]
	direct_gray_code(set([0]))
	return result