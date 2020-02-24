a = set()
b = set()
for i in range(1,6):
  a.add(i)
for i in range(2,7):
  b.add(i)
s = a & b
print(a)
print(b)
print(s)