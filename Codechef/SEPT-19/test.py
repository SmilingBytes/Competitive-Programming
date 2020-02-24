import itertools as it
import sys
import math

sys.stdin = open('in.txt', 'r') 
sys.stdout = open('out.txt', 'w')

n, m = map(int, sys.stdin.readline().split())
a = list(map(int, sys.stdin.readline().split()))


def combinations(iterable, r):
    pool = tuple(iterable)
    n = len(pool)
    if r > n:
        return
    indices = [i for i in range(r)]
    yt = set()
    for i in range(r):
        if pool[i] in yt:
            break
        else:
            yt.add(pool[i])
    if (len(yt) == r):
        yield 1
    while True:
        for i in reversed(range(r)):
            if indices[i] != i + n - r:
                break
        else:
            return
        indices[i] += 1
        for j in range(i+1, r):
            indices[j] = indices[j - 1] + 1
        yt = set()
        for i in indices:
            if pool[i] in yt:
                break
            else:
                yt.add(pool[i])
        if (len(yt) == r):
            yield 1

cnt = 0
for i in range(3, m+1): 
  for val in combinations(a, i):
    cnt += 1
k2 = int(math.factorial(n) / (math.factorial(n - 2) * 2))
k2 -= (n//2)
if (m <= 2):
    print(n + 1)
else:
    print(1+n+k2+cnt)