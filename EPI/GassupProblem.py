import collections
MPG = 20
def find_ample_city(gallons, distance):
	CityAndRemainingGas = collections.namedtuple('CityAndRemainingGas', ('city', 'remaining_gallons'))
	city_and_remaining_gas = CityAndRemainingGas(0, 0)
	num_cities = len(gallons)
	remaining_gallons = 0
	for i in range(1, num_cities):
		remaining_gallons += gallons[i - 1] - distance[i - 1] // MPG
		if remaining_gallons < city_and_remaining_gas.remaining_gallons:
			city_and_remaining_gas = CityAndRemainingGas(i, remaining_gallons)
	return city_and_remaining_gas.city
