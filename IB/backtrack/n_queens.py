class Solution:
    # @param A : integer
    # @return a list of list of strings
	board = [[False] * 20 for i in range(20)]
	n = -1
	def is_safe(self,row, col):
		for j in range(col):
			if self.board[row][j]: return False
		for i in range(row):
			if self.board[i][col]: return False
		i, j = row, col
		while i >= 0 and j >= 0:
			if self.board[i][j]: return False
			i, j = i - 1, j - 1
		i, j = row, col
		while i < self.n and j >= 0:
			if self.board[i][j]: return False
			i, j = i + 1, j - 1
		return True
	def add_to_result(self, result):
		temp = []
		for i in range(self.n):
			row = self.board[i][:self.n]
			temp.append(''.join(['Q' if c else '.' for c in row]))
		result.append(temp)
	def NQueen(self, col, result):
		if col == self.n:
			self.add_to_result(result)
			return
		for row in range(self.n):
			if self.is_safe(row, col):
				self.board[row][col] = True
				self.NQueen(col + 1, result)
				self.board[row][col] = False
		return
	def solveNQueens(self, A):
		result = []
		self.n = A
		self.NQueen(0, result)
		return result

sol = Solution()
print(sol.solveNQueens(4))


