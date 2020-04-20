def generate_power_set(input_set):
	def direct_power_set(input_set, power_set):
		if len(input_set) == 0:
			power_set.append([])
			return 1
		rem_set_count = direct_power_set(input_set[1:], power_set)
		for i in range(rem_set_count):
			power_set.append([input_set[0]] + power_set[i])
		return 2 * rem_set_count
	power_set = []
	direct_power_set(input_set, power_set)
	return power_set


def permutations(input_string):
	def direct_permutations(input_string):
		output = []
		if len(input_string) == 0:
			output.append("")
			return output
		first_char = input_string[0]
		rem_perms = direct_permutations(input_string[1:])
		for perm in rem_perms:
			for i in range(len(perm) + 1):
				prefix = perm[:i]
				suffix = perm[i:]
				output.append(prefix + first_char + suffix)
		return output
	return direct_permutations(input_string)
perms = permutations("RELINQUISH")
for perm in perms:
	if perm[0] == 'L' or perm[0] == 'N' or perm[0] == 'U' or perm[0] == 'S' or perm[0] == 'H':
		print(perm)

			