if __name__ == "__main__":
	n = int(input())
	description = str(input())
	s = -1
	t = -1
	n = len(description)
	for i in range(n):
		if description[i] != '.':
			if description[i] == 'R':
				while description[i] == 'R':
					i += 1
				print(i, i + 1)
			else:
				print(i + 1, i)
			break
	


		
