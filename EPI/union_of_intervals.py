import collections
Interval = collections.namedtuple('Interval',('start','end'))
Endpoint = collections.namedtuple('Endpoint',('time','is_start'))
def union_of_intervals(intervals):
	E = ([Endpoint(interval.start, True) for interval in intervals] + \
		[Endpoint(interval.end, False) for interval in intervals])
	E.sort(key=lambda i: (i.time, not i.is_start))
	start = E[0].time
	counter, result = 0, []
	for i,endpoint in enumerate(E):
		if endpoint.is_start:
			counter += 1
		else:
			counter -= 1
		if counter == 0:
			result.append(Interval(start, endpoint.time))
			if i + 1 < len(E):
				start = E[i + 1].time
	return result

if __name__ == "__main__":
	intervals = [Interval(0, 3), Interval(1, 1), Interval(2, 4), Interval(3, 4), Interval(5, 7), Interval(7, 8), \
		 Interval(8, 11), Interval(9, 11), Interval(12, 14), Interval(12, 16), Interval(13, 15), Interval(16, 17)]
	print(union_of_intervals(intervals))
		



