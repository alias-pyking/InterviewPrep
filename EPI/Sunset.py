def examine_buildings_with_sunset(buildings):
    result, n = [], len(buildings)
    result.append(buildings[0])
    for i in range(1,len(buildings)):
        while result and buildings[i] >= result[-1]:
            result.pop()
        if not result or buildings[i] < result[-1]:
            result.append(buildings[i])
    return result
if __name__ == "__main__":
    tests = [[8,4,5,10,9,7,5,12,8],[9,10,11,90,10,4]]
    for test in tests:
        print(examine_buildings_with_sunset(test))
