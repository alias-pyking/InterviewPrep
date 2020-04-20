import collections
PairedTask = collections.namedtuple('PairedTask',('task_1','task_2'))
def assignment(tasks):
	tasks.sort()
	i = 0
	j = len(tasks) - 1
	optimum_assignment = []
	return [
		PairedTask(tasks[i], tasks[~i])
		for i in range(len(tasks) //2)
	]

if __name__ == "__main__":
	tasks = [5, 2, 1, 6, 4, 4]
	print(assignment(tasks))

 