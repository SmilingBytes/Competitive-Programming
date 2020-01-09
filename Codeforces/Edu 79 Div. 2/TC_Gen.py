import sys
import random

def main():
  sys.stdout = open('in.txt', 'w')
  t = random.randint(100, 10000)
  print(t)
  for _ in range(t):
    n = random.randint(1, 100)
    s = random.randint(1, 100)
    p = random.randint(1, 300)
    print(n, s, p)
    # for _ in range(n):
    #   a = random.randint(1, 20)
    #   print(a, end=" ")
    # print()

if __name__ == "__main__":
  main()
