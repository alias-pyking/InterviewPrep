class Solution:
	MAPPING = ['0','1','abc','def','ghi','jkl','mno','pqrs','tuv','wxyz']
	def letterCombinations(self, phone_number):
		mnemonics, partial_mnemonic = [], [0] * len(phone_number)
		def phone_mnemonics_helper(digit):
			if digit == len(phone_number):
				mnemonics.append(''.join(partial_mnemonic))
			else:
				for c in self.MAPPING[int(phone_number[digit])]:
					partial_mnemonic[digit] = c
					phone_mnemonics_helper(digit + 1)
		phone_mnemonics_helper(0)
		mnemonics.sort()
		return mnemonics
	
sol = Solution()
print(sol.letterCombinations("23"))