import math, heapq
class Star:
    def __init__(self, x, y, z):
        self.x, self.y, self.z = x, y, z
    
    @property
    def distance(self):
        return math.sqrt(self.x**2 + self.y**2 + self.z**2)

def find_closest_k_stars(stars, k):
    max_heap = []
    for star in stars:
        heapq.heappush(max_heap,(-star.distance,star))
        if len(max_heap) == k + 1:
            heapq.heappop(max_heap)
    
    return [s[0] for s in heapq.nlargest(k,max_heap)]
 

