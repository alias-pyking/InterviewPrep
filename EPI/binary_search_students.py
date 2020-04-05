import bisect,collections
Student = collections.namedtuple('Student',('name','grade_point_average'))

def comp_gpa(student):
    return (-student.grade_point_average,student.name)

def search_student(students,target,comp_gpa):
    i = bisect.bisect_left([comp_gpa(s) for s in students], comp_gpa(target))
    return students[i] if 0<= i < len(students) and students[i] == target else None


students = [Student('Shubham',90),Student('Shivang',80),Student('Pushpi',79), Student('Ranjan',76)]
target = students[3]

print(search_student(students,target,comp_gpa))
