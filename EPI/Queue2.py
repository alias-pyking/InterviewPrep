import collections
class Queue(object):
    def __init__(self):
        self._entries = collections.deque()
        self._candidates_for_max = collections.deque()

    def enqueue(self, x):
        self._entries.append(x)
        while self._candidates_for_max and self._candidates_for_max[-1] < x:
            self._candidates_for_max.pop()
        self._candidates_for_max.append(x)
    def deque(self):
        if self._entries:
            result = self._entries.popleft()
            if self._candidates_for_max[0] == result:
                self._candidates_for_max.popleft()
            return result
        raise IndexError('Queue is Empty')
    