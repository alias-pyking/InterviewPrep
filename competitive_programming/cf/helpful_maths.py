


if __name__ == "__main__":
	s = str(input())
	numbers = list(sorted([int(x) for x in s if x not in ['+']]))
	output = []
	j = 1
	for i in range(len(numbers)):
		output.append(str(numbers[i]))
		if j < len(s):
			output.append(s[j])
		j += 2
	print(''.join(output))

