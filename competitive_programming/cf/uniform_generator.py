

def get_choice(step, mod):
	result = [0] * mod
	calculated = {}
	calculated[0] = 1
	for i in range(1,mod):
		result[i] = (result[i - 1] + step) % mod
		if result[i] in calculated:
			return "Bad Choice"
		calculated[result[i]] = 1
	return "Good Choice"


if __name__ == "__main__":
	step, mod = (int(x) for x in input().split(' '))
	print(get_choice(step,mod))
	
	
