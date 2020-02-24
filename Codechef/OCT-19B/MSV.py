import sys

def factor(i, d):
  j = 1
  while j*j <= i:
    if (i % j == 0):
      d[j] += 1
      if (i // j != j):
        d[i // j]+= 1
    j += 1
  return d[i] - 1
def main():
  sys.stdin = open('in.txt', 'r')
  # sys.stdout = open('out.txt', 'w')
  t = int(sys.stdin.readline())
  for _ in range(t):
    n = int(sys.stdin.readline())
    a = list(map(int, sys.stdin.readline().split()))
    d = [0] * ((10**6) + 1)
    ans = 0
    for i in a:
      ans = max(factor(i, d), ans)
    print(ans)


if __name__ == "__main__":
  main()
