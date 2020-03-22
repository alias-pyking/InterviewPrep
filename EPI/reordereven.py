def even_odd(A):
    next_even, next_odd = 0, len(A) - 1
    while next_even < next_odd:
        if A[next_even] % 2== 0:
            next_even +=1 
        else:
            A[next_even],A[next_odd] = A[next_odd], A[next_even]
            next_odd -= 1

A = [2,10,2,1,20,1,23,4,1,90,14,13,9012312,12311023,123123,23231]
even_odd(A)
print(A)

class Rectangle:
    def __init__(self):
        self.length = 0
        self.breadth = 0
    def set_data(self, length, breadth):
        self.length = length
        self.breadth = breadth
    def get_length(self):
        return self.length
    def get_breadth(self):
        return self.breadth
    def area(self):
        return self.length * self.breadth
    def print_area(self):
        print('Area {}'.format(self.area()))
rect = Rectangle()
rect.set_data(10,20)
print(rect.area())
rect.print_area()