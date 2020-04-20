import collections,operator
Interval = collections.namedtuple('Interval',('left','right'))
def find_minimum_visits(intervals):
	intervals.sort(key=operator.attrgetter('right'))
	num_visits, last_visit = 0, float('-inf')
	for interval in intervals:
		if interval.left > last_visit:
			num_visits += 1
			last_visit = interval.right
	return num_visits

