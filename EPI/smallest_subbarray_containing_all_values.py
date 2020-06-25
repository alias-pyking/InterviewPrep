import collections
def find_smalles_subarray_covering_set(paragraph, keywords):
    keywords_to_cover = collections.Counter(keywords)
    remaing_to_cover = len(keywords_to_cover)
    result = (-1, -1)
    left = 0
    for right, p in enumerate(paragraph):
        if p in keywords_to_cover:
            keywords_to_cover[p] -= 1
            if keywords_to_cover[p] >= 0:
                remaing_to_cover -= 1
        while remaing_to_cover == 0:
            if result == (-1, -1) or right - left < result[1] - result[0]:
                result = (left,right)
            p1 = paragraph[left]
            if p1 in keywords:
                keywords_to_cover[p1] += 1
                if keywords_to_cover[p1] > 0:
                    remaing_to_cover += 1
            left += 1
    if result == (-1, -1):
        return ''
    return paragraph[result[0]:result[1] + 1]

if __name__ == "__main__":
    paragraph = "ADOBECODEBANC";
    keywords = "ABC"
    subbarray = find_smalles_subarray_covering_set(paragraph,keywords)
    print(subbarray)
