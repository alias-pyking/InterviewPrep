if __name__ == "__main__":
	sequence = str(input()).split('|')
	w = str(input())
	first = sequence[0]
	second = sequence[1]
	for i in w:
		if len(first) < len(second):
			first = first + i
		else:
			second = second + i
	if len(first) == len(second):
		print('{}|{}'.format(first, second))
	else:
		print('Impossible')

