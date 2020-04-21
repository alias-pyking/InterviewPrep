def largest_rectangle_in_skyline(heights):
	pilar_indices, max_rectangle_area = [], 0
	for i, h in enumerate(heights + [0]):
		while pilar_indices and heights[pilar_indices[-1]] >= h:
			height = heights[pilar_indices.pop()]
			width = i if not pilar_indices else i - pilar_indices[-1] - 1
			max_rectangle_area = max(max_rectangle_area, height * width)
		pilar_indices.append(i)
	return max_rectangle_area

if __name__ == "__main__":
	heights = [1, 4, 2, 5, 6, 3, 2, 6, 6, 5, 2, 1, 3]
	print(largest_rectangle_in_skyline(heights))