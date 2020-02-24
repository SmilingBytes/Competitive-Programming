import sys
n, m = map(int, sys.stdin.readline().split())
area = n * m
ans = (area // 2) + (area & 1)
print(ans)
