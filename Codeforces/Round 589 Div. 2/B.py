mod = 1000000007
import sys

def choose(n, k):
    """
    A fast way to calculate binomial coefficients by Andrew Dalke (contrib).
    """
    if 0 <= k <= n:
        ntok = 1
        ktok = 1
        for t in range(1, min(k, n - k) + 1):
            ntok *= n
            ktok *= t
            n -= 1
        return (ntok // ktok) % mod
    else:
        return 0


def main():
  sys.stdin = open('in.txt', 'r')
  
  h, w = map(int, sys.stdin.readline().split())
  rd = list(map(int, sys.stdin.readline().split()))
  cd = list(map(int, sys.stdin.readline().split()))
  a = [x[:] for x in [[0] * w] * h]
  for i in range(1, h):
    for j in range(rd[i]):
      a[i][j] += 1
  for i in range(1, w):
    for j in range(cd[i]):
      a[j][i] += 1

  cnt = 0
  for i in range(2, h):
    for j in range(2, w):
      if (a[i][j] == 0):
        if (a[i - 1][j] != 2 or a[i][j - 1] != 2):
          cnt += 1
  ans = 0
  # cnt += 1
  for i in range(1 , cnt):
    ans = (ans + choose(cnt, i)) % mod
  print(ans)
if __name__ == "__main__":
  main()
