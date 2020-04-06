def find_minimum_subarray_sequential(paragraph, keywords):
	keywords_to_idx = {k: i for i, k in enumerate(keywords)}
	
	latest_occurence = [-1] * len(keywords)
	shortest_subarray_length =[float('inf')]*len(keywords)
	shortest_distance = float('inf')
	result = (-1,-1)
	for i, p in enumerate(paragraph):
		if p in keywords_to_idx:
			keyword_idx = keywords_to_idx[p]
			if keyword_idx == 0:
				shortest_subarray_length[keyword_idx] = 1
			elif shortest_subarray_length[keyword_idx - 1] != float('inf'):
				distance_to_previous_keyword = (i - latest_occurence[keyword_idx - 1])
				shortest_subarray_length[keyword_idx] = (
					shortest_subarray_length[keyword_idx - 1] +
					distance_to_previous_keyword)
			latest_occurence[keyword_idx] = i
			
			if keyword_idx == len(keywords) - 1 and shortest_subarray_length[-1] < shortest_distance:
				shortest_distance = shortest_subarray_length[-1]
				result = (i - shortest_distance + 1, i)
				
	return result

if __name__ == "__main__":
	paragraph = "Thor is god of thunder he can manupulate the thunder and weather with his powers\
				he power to talk in any language he wants";
	paragraph = paragraph.split(' ')
	keywords = "thunder and weather";
	keywords = keywords.split(' ')
	print(find_minimum_subarray_sequential(paragraph, keywords))


