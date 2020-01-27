def db_value(x):
    x = str(x)
    decimal = 0
    t = len(x) - 1
    for i in range(0,len(x)):
        decimal +=  int(x[i]) * (2**t)
        t -= 1
    return decimal

a = [db_value(x) for x in range(0,10)]
b = [db_value(x) for x in range(10,20)]
c = [db_value(x) for x in range(20,30)]
d = [db_value(x) for x in range(30,40)]
e = [db_value(x) for x in range(40,50)]
f = [db_value(x) for x in range(50,60)]
print(a)
print(b)
print(c)
print(d)
print(e)
print(f)
print('-----------------------------')

a = [db_value(x) for x in range(90,100)]
b = [db_value(x) for x in range(100,110)]
c = [db_value(x) for x in range(110,120)]
print(a)
print(b)
print(c)

print('---------------------------------')
a = [db_value(x) for x in range(190,200)]
b = [db_value(x) for x in range(200,210)]
c = [db_value(x) for x in range(210,220)]
print(a)
print(b)
print(c)