import collections
Interval = collections.namedtuple('Interval',('start','end'))
def merge_intervals(disjoint_intervals, new_interval):
	i, result = 0, []
	while i < len(disjoint_intervals) and new_interval.start > disjoint_intervals[i].end:
		result.append(disjoint_intervals[i])
		i += 1
	while i < len(disjoint_intervals) and new_interval.end > disjoint_intervals[i].start:
		new_interval = Interval(min(disjoint_intervals[i].start, new_interval.start), \
								max(disjoint_intervals[i].end, new_interval.end))
		i += 1
	return result + [new_interval] + disjoint_intervals[i:]

if __name__ == "__main__":
	disjoint_intervals = [Interval(-4, -1), Interval(1, 2), Interval(3, 5), Interval(6, 9), Interval(11, 12)]
	new_interval = Interval(1, 8)
	print(merge_intervals(disjoint_intervals, new_interval))


