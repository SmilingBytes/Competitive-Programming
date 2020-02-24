n = int(input())
a = list(map(str, input().split()))
ln = len(a[0])
# def func(x, y):
#     return int(''.join(x[i] + y[i] for i in range(ln)))


num = 0
for i in range(n):
    num += int(''.join(a[i][j] + a[i][j] for j in range(ln)))

print((num * n) % 998244353)
