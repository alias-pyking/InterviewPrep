def compute_fair_bounus(lines_of_code):
	tickets = [1] * len(lines_of_code)
	for i in range(1, len(lines_of_code)):
		if lines_of_code[i] > lines_of_code[i - 1]:
			tickets[i] = tickets[i - 1] + 1
	for i in reversed(range(len(lines_of_code) - 1)):
		if lines_of_code[i] > lines_of_code[i + 1]:
			tickets[i] = max(tickets[i], tickets[i + 1] + 1)
	return sum(tickets)
