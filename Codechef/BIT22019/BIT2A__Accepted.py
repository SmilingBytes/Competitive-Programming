import sys


def main():
  sys.stdin = open('in.txt', 'r') 
  sys.stdout = open('out.txt', 'w')
  t = int(sys.stdin.readline())
  for _ in range(t):
    n = int(sys.stdin.readline())
    a = list(map(int, sys.stdin.readline().split()))
    cnt = 1
    for i in range(n-1):
      if (a[i] != a[i + 1]):
        for _ in range(cnt):
          print(n - i - 1, end=" ")
        cnt = 1
      else:
        cnt += 1
    for _ in range(cnt):
      print(0, end=" ")
    print()


if __name__ == "__main__":
  main()
