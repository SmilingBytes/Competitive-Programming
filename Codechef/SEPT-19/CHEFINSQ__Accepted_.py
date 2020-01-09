from sys import stdin, stdout
import math


def main():
  t = int(stdin.readline())
  for _ in range(t):
    n, k = map(int, stdin.readline().split())
    a = list(map(int, stdin.readline().split()))
    a.sort()
    mx = a[k - 1]
    nn, r = 0, 0
    for i in range(k):
      if a[i] == mx:
        r += 1
    for i in range(k, n):
      if (a[i] == mx):
        nn += 1
      else:
        break
    
    nn += r
    ans = math.factorial(nn) // (math.factorial(nn - r) * math.factorial(r))
    print(ans)


if __name__ == "__main__":
  main()
