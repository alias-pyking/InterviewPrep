if __name__ == "__main__":
	sequence = str(input()).split('|')
	wt = str(input())
	n1 = len(sequence[0])
	n2 = len(sequence[1])
	if n1 == n2 and len(wt) % 2 != 0:
		res = "Impossible"
	elif n1 > n2 and n2 + len(wt) == n1:
		res = str(sequence[0] + '|' + sequence[1] + wt)
	elif n2 > n1 and n1 + len(wt) == n2:
		res = str(sequence[0] + wt + '|' + sequence[1])
	else:
		i = 0
		size = len(wt)
		res = "Impossible"
		while i < len(wt):
			if len(sequence[0]) < len(sequence[1]):
				sequence[0] = sequence[0] + wt[i]
			elif len(sequence[1]) < len(sequence[0]):
				sequence[1] = sequence[1] + wt[i]
			else:
				if size - i % 2 != 0:
					res = "Impossible"
					break
				else:
					sequence[0] = sequence[0] + wt[i:(i + i // 2) + 1]
					sequence[1] = sequence[1] + wt[(i + i // 2) + 1:]
					res = str(sequence[0] + '|' + sequence[1])
			i += 1
	print(res)

