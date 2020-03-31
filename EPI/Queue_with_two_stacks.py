class Queue:
    def __init__(self):
        self._enq = self._deq = []
    def enqueue(self,x):
        self._enq.append(x)

    def dequeue(self):
        if len(self._deq) == 0:
            if len(self._enq) == 0:
                raise IndexError('empty queue')
            while self._enq:
                self._deq.append(self._enq.pop())
        return self._deq.pop()
        
    











# 1     6
# 2     5
# 3     4
# 4     3
# 5     2
# 6     1