def are_ordered(possible_anc_or_desc_0, possible_anc_or_desc_1, middle):
	search_0, search_1 = possible_anc_or_desc_0, possible_anc_or_desc_1
	while ((search_0 is not possible_anc_or_desc_1) and (search_0 is not middle)\
		and (search_1 is not possible_anc_or_desc_0) and (search_1 is not middle)) and (search_0 or search_1):
		search_0 = search_0.left if search_0.data > middle.data else search_0.right
		search_1 = search_1.left if search_1.data > middle.data else search_1.right
	if (search_0 is not middle and search_1 is not middle)\
		or search_0 is possible_anc_or_desc_1\
		or search_1 is possible_anc_or_desc_0:
		return False
	def check(source, target):
		while source and source is not target:
			source = source.left if source.data > target.data else source.right
		return source is target
	return check(middle, possible_anc_or_desc_0 if search_1 is middle else possible_anc_or_desc_1)
	
