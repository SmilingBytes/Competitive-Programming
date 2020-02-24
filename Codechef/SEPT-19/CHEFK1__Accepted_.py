import sys

def main():
  sys.stdin = open('in.txt', 'r') 
  sys.stdout = open('out.txt', 'w')

  t = int(sys.stdin.readline())
  for _ in range(t):
    n, m = map(int, sys.stdin.readline().split())
    max_m = (n * (n - 1) // 2) + n
    if n == 1:
      print(int(m)) if m <= 1 else print(-1)
    elif m > max_m or m == 0 or m < n - 1:
      print(-1)
    elif n == 2:
      print(1) if m == 1 else print(2)
    elif m <= n + 1:
      print(2)
    elif m <= 2 * n:
      print(3)
    else:
      k = (((m - n) * 2) / n) + 1
      print(int(k + 1)) if int(k) < k else print(int(k))

if __name__ == "__main__":
  main()
