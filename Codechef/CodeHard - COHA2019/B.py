import sys
t = int(sys.stdin.readline())
for _ in range(t):
    n = int(sys.stdin.readline())
    a = map(int, sys.stdin.readline().split())
    a = sorted(a)
    print(a)
    print("Isa") if (a[n - 1] == a[n - 2]) else print("Gaitonde")
