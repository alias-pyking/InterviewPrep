if __name__ == "__main__":
	
	map = {'A':0,'B':0,'C':0}
	s = str(input())
	if s[1] == '>':
		map[s[0]] += 1
	else:
		map[s[2]] += 1
	s = str(input())
	if s[1] == '>':
		map[s[0]] += 1
	else:
		map[s[2]] += 1
	s = str(input())
	if s[1] == '>':
		map[s[0]] += 1
	else:
		map[s[2]] += 1
	if map['A'] == 1 and map['B'] == 1 and map['C'] == 1:
		print('Impossible')
	else:
		ans = str()
		if map['A'] == 0: ans+='A'
		elif map['B'] == 0: ans +='B'
		elif map['C'] == 0: ans += 'C'
		
		if map['A'] == 1:ans += 'A'
		elif map['B'] == 1: ans += 'B'
		elif map['C'] == 1: ans += 'C'

		if map['A'] == 2:ans += 'A'
		elif map['B'] == 2: ans += 'B'
		elif map['C'] == 2: ans += 'C'
		print(ans)


