def gcd(x, y):
	if x > y:
		return gcd(y, x)
	if x == 0:
		return y
	else:
		return gcd(y % x, x)
	

if __name__ == "__main__":
	tests = [(22,11), (5, 15), (6, 18), (90, 100)]
	print([gcd(x, y) for x, y in tests])
	
		
