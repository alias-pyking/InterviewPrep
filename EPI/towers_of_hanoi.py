def move(n, origin, des, buffer):
	if n == 0:
		return
	move(n - 1, origin, buffer, des)
	des.append(origin.pop())
	move(n - 1, buffer, des, origin)


origin = [5, 4, 3, 2, 1]
buffer 

