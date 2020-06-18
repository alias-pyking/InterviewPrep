import collections
class MinStack:
    # @param x, an integer
	ElementWithCachedMin = collections.namedtuple('ElementWithCachedMin', ('element', 'min'))
	def __init__(self):
		self._element_with_cahced_min = []
	def empty(self):
		return len(self._element_with_cahced_min) == 0

	def getMin(self):
		return self._element_with_cahced_min[-1].min

    def push(self, x):
		self._element_with_cahced_min.append(self.ElementWithCachedMin(x, x \
			if self.empty() else min(x, self.getMin())))

    def pop(self):
		if self.empty():
			return
		self._element_with_cahced_min.pop()

    def top(self):
		if self.empty():
			return - 1
		return self._element_with_cahced_min[-1].element

