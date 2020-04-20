def minimize_waiting_time(service_times):
	service_times.sort()
	minimum_waiting_time = 0
	for i, service_time in enumerate(service_times):
		num_remaining_queries = len(service_time) - (i + 1)
		minimum_waiting_time += service_time * num_remaining_queries
	return minimum_waiting_time

