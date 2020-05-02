
def get_ans(mat):
	for i in range(3):
		for j in range(3):
			if mat[i][j] == mat[i][j + 1] and mat[i][j + 1] == mat[i + 1][j + 1]:
				return "YES"
			elif mat[i][j +1] == mat[i + 1][j + 1] and mat[i + 1][j + 1] == mat[i + 1][j]:
				return "YES"
			elif mat[i][j] == mat[i +1][j] and mat[i + 1][j] == mat[i + 1][j + 1]:
				return "YES"
			elif mat[i][j] == mat[i +1][j] and mat[i][j] == mat[i][j + 1]:
				return "YES"
	return "NO"

if __name__ == "__main__":
	mat = []
	mat.append(str(input()))
	mat.append(str(input()))
	mat.append(str(input()))
	mat.append(str(input()))
	print(get_ans(mat))
	
				