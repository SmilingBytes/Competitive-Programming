import sys


def main():
  sys.stdin = open('in.txt', 'r')
  t = int(sys.stdin.readline())
  for _ in range(t):
    x, y, k, n = map(int, sys.stdin.readline().split())
    pg = x - y
    flag = False
    for _ in range(n):
      page, price = map(int, sys.stdin.readline().split())

      if page >= pg and price <= k:
        flag = True
    print("LuckyChef") if (flag is True) else print("UnluckyChef")

if __name__ == "__main__":
  main()
