
def get_index(row, c):
	for i in range(0, len(row)):
		if row[i] == c:
			return i

if __name__ == "__main__":
	first_row = ['q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p']
	second_row = ['a','s', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';']
	third_row = ['z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/']
	shift = str(input())
	sequence = str(input())
	if shift == 'R':
		result = []
		for c in sequence:
			if c in first_row:
				req_idx = get_index(first_row, c) - 1
				result.append(first_row[req_idx])
			elif c in second_row:
				req_idx = get_index(second_row, c) - 1
				result.append(second_row[req_idx])
			else:
				req_idx = get_index(third_row, c) - 1
				result.append(third_row[req_idx])
		print(''.join(result))
	else:
		result = []
		for c in sequence:
			if c in first_row:
				req_idx = get_index(first_row, c) + 1
				result.append(first_row[req_idx])
			elif c in second_row:
				req_idx = get_index(second_row, c) + 1
				result.append(second_row[req_idx])
			else:
				req_idx = get_index(third_row, c) + 1
				result.append(third_row[req_idx])
		print(''.join(result))
