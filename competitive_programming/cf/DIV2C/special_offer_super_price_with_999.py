import collections
def cnt_9(string):
	i, ans = len(string) - 1, 0
	while i >= 0:
		if string[i] == '9':
			ans += 1
		else: break
		i -= 1
	return ans
def main():
	p, d = (int(x) for x in input().split(' '))
	i = 18;
	ans = p
	while i >= 1:
		c = p - p % 10 ** i - 1
		if c == -1:
			i -= 1
			continue
		if p - c <= d:
			ans = c
			break
		i -= 1
	if cnt_9(str(p)) >= cnt_9(str(ans)):
		ans = p
	print(ans)


if __name__ == "__main__":
	main()
	# print(cnt_9('123909313201231239999'),cnt_9('23213999909099'))