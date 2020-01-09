import sys
t = int(sys.stdin.readline())
for _ in range(t):
    n, m = map(int, sys.stdin.readline().split())
    rn = n // m
    ans = 0
    for i in range(1, rn + 1):
        ans = ans + (i * m) % 10
    print(ans)
