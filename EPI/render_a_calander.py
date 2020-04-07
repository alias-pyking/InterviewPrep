import collections
Event = collections.namedtuple('Event', ('start', 'finish'))

EndPoint = collections.namedtuple('Endpoint',('time','is_start'))

def maximum_parallel_events(events):
	E = ([EndPoint(event.start, True) for event in events] + [EndPoint(event.finish, False) for event in events])
	E.sort(key=lambda e: (e.time, not e.is_start))
	print(E)
	max_parallel_events = 0
	counter = 0
	for endpoint in E:
		if endpoint.is_start:
			counter += 1
		else:
			counter -= 1
		max_parallel_events = max(max_parallel_events, counter)
	return max_parallel_events


if __name__ == "__main__":
	events = [Event(2, 5), Event(4, 5), Event(6, 9), Event(6, 7), Event(8, 9)]
	print(maximum_parallel_events(events))
