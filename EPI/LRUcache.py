import collections
class LRUCache:
    def __init__(self, capacity):
        self.key_value = collections.OrderedDict()
        self._capacity = capacity
    def get(self, key):
        if not key in self.key_value:
            return -1
        value = self.key_value.pop(key)
        self.key_value[key] = value
        return value
    def set(self, key, value):
        if key in self.key_value:
            value = self.key_value.pop(key)
        elif self._capacity <= len(self.key_value):
            self.key_value.popitem(last= False)
        self.key_value[key] = value
    def erase(self,key):
        return self.key_value.pop(key,None) is not None


cache = LRUCache(2)
cache.set(2,1)
cache.set(2,2)
print(cache.get(2))
cache.set(1, 1)
cache.set(4, 1)
print(cache.get(2))



        