
def column_to_number(s):  
    result = 0;  
    for B in range(len(s)):  
        result *= 26;  
        result += ord(s[B]) - ord('A') 
    return result;

def solve(spreadsheet):
	n, m = len(spreadsheet), len(spreadsheet[0])
	for i in range(n):
		for j in range(m):
			if type(spreadsheet[i][j]) == str:
				tokens = spreadsheet[i][j].split('+')
				tokens[0] = tokens[0][1:]
				res = 0
				for token in tokens:
					for k in range(len(token)):
						if token[k].isdigit():
							break
					row = int(token[k:]) - 1
					col = column_to_number(token[: k])
					res += spreadsheet[row][col]
				spreadsheet[i][j] = res
	for row in spreadsheet:
		print(*row)

if __name__ == "__main__":
	t = int(input())
	while t > 0:
		m, n = (int(x) for x in input().split(' '))
		spreadsheet = [[]*m] * n
		for i in range(n):
			spreadsheet[i] = input().split(' ')
		for i in range(n):
			for j in range(m):
				if spreadsheet[i][j][0] != '=':
					spreadsheet[i][j] = int(spreadsheet[i][j])
		solve(spreadsheet)
		t -= 1
