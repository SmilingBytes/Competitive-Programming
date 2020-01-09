import sys
import itertools as it

def main():
  sys.stdin = open('in.txt', 'r')
  # sys.stdout = open('out.txt', 'w')
  a = list(map(int, sys.stdin.readline().split()))
  m = sum(a)
  if (m % 2 == 0):
    m = m // 2
    for i in range(1, 4):
      for val in it.combinations(a, i):
        s = 0
        for x in val:
          s += x
          if s == m:
            print("YES")
            exit()
  print("NO")


if __name__ == "__main__":
  main()
