


def main():
	poly_hedrons = {
	'Tetrahedron':4,
	'Cube':6,
	'Octahedron':8,
	'Dodecahedron':12,
	'Icosahedron':20,
	}
	n = int(input())
	ans = 0
	for i in range(n):
		ph = str(input())
		ans += poly_hedrons[ph]
	print(ans)


if __name__ == '__main__':
	main()