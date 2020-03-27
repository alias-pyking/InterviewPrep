import collections
class Stack:
    ElementWithCachedMax = collections.namedtuple('ElmentWithCachedMax',('element','max'))
    def __init__(self):
        self._elment_with_cached_max = []
    def empty(self):
        return len(self._elment_with_cached_max) == 0
    def max(self):
        if self.empty():
            raise IndexError('max(): on empty stack')
        return self._elment_with_cached_max[-1].max
    def pop(self):
        if self.empty():
            raise IndexError('pop(): on empyt stack')
        return self._elment_with_cached_max.pop().element
    def push(self,x):
        self._elment_with_cached_max.append(self.ElementWithCachedMax(x,\
            x if self.empty() else max(x,self.max())))

    
 