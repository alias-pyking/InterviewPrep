import collections
def nearest_repeated_entry(A):
    dictionary = collections.defaultdict()
    min_dist = float('inf')
    for i,v in enumerate(A):
        if v in dictionary:
            last_word_equal = dictionary[v]
            min_dist = min(min_dist, i - last_word_equal)
        dictionary[v] = i
    return min_dist if min_dist != float('inf') else -1

if __name__ == "__main__":
    A = ['All','work','and','no','play','makes','for','no','work','fun','and','no','results']
    print(nearest_repeated_entry(A))

