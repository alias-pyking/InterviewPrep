import collections
class Queue:
    def __init__(self):
        self._data = collections.deque()
    def enqueue(self, x):
        self._data.append(x)
    def dequeue(self):
        self._data.popleft()
    def max(self):
        return max(self._data)
class Solution:

    def slidingMaximum(self,A, b):
        que = Queue()
        for i in range(b):
            que.enqueue(A[i]);
        res = []
        res.append(que.max())
        i = b
        while i < len(A):
            que.dequeue()
            que.enqueue(A[i])
            res.append(que.max())
            i += 1
        return res

sol = Solution()
print(sol.slidingMaximum([1], 1))
