MAPPING = ('0','1','ABC','DEF','GHI','JKL','MNO','PQRS','TUV','WXYZ')

def phone_mnemonics(phone_number):
    mnemonics, partial_mnemonic = [],[0]*len(phone_number)
    def phone_mnemonics_helper(digit):
        if digit == len(phone_number):
            mnemonics.append(''.join(partial_mnemonic))
        else:
            for c in MAPPING[int(phone_number[digit])]:
                partial_mnemonic[digit] = c
                phone_mnemonics_helper(digit + 1)
    phone_mnemonics_helper(0)
    return mnemonics

print(phone_mnemonics('298929812'))