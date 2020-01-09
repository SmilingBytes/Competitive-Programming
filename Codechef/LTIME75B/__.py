import sys
a = [0]
a.extend(list(map(int, sys.stdin.readline().split())))
a.extend([0])
a += [0]
print(a)
