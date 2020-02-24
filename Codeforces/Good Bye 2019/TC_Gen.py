import sys
import random

def main():
  sys.stdout = open('in.txt', 'w')
  t = random.randint(100, 10000)
  print(t)
  for _ in range(t):
    n = random.randint(1, 10)
    k = 2
    print(n, k)
    prev = -1
    for _ in range(n):
      foo = [-1, 1, -1, 2, -1]
      d = random.choice(foo)
      while d == prev and prev != -1:
        d = random.choice(foo)
      prev = d
      print(d, end=" ")
    print()
if __name__ == "__main__":
  main()
