import sys
import random
# print(random.randint(0,9))

def main():
  sys.stdout = open('in.txt', 'w')
  t = random.randint(1, 300)
  print(t)
  for _ in range(t):
    n = random.randint(1, 100)
    m = random.randint(1, 10)
    q = random.randint(1, 5)
    print(n, m, q)
    for _ in range(q):
      x = random.randint(1, n)
      y = random.randint(1, m)
      print(x, y)
      

if __name__ == "__main__":
  main()
