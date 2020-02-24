n, k = map(int, input().split())
d = [0] * (k + 1)
for _ in range(n):
    d[int(input())] += 1
print(n - (sum(x % 2 for x in d) // 2))
