import collections
Person = collections.namedtuple('Person',('age','name'))
def groupby_age(peoples):
	age_to_count = collections.Counter([person.age for person in peoples])
	age_to_offset, offset = {}, 0
	for age, count in age_to_count.items():
		age_to_offset[age] = offset
		offset += count
	while age_to_count:
		from_age = next(iter(age_to_offset))
		from_idx = age_to_offset[from_age]
		to_age = peoples[from_idx].age
		to_idx = age_to_offset[to_age]
		peoples[from_idx], peoples[to_idx] = peoples[to_idx], peoples[from_idx]
		age_to_count[to_age] -= 1
		if age_to_count[to_age]:
			age_to_offset[to_age] += 1
		else:
			del age_to_count[to_age]

if __name__ == "__main__":
	students = [Person(13,'shubh'),Person(15,'sk'),Person(14,'sks'),Person(13,'shubham'),Person(15,'kumar')]
	groupby_age(students)
	print(students)

