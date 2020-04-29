if __name__ == "__main__":
	inp = str(input())
	list = inp.split('WUB')
	list = [x for x in list if x != '']
	print(*list)
	