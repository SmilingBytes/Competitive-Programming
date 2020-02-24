import sys


def main():
  # sys.stdin = open('in.txt', 'r') 
  # sys.stdout = open('out.txt', 'w')
  t = int(sys.stdin.readline())
  for _ in range(t):
    n = int(sys.stdin.readline())
    c = list(map(int, sys.stdin.readline().split()))
    x = int(sys.stdin.readline())
    if n == 1:
      print(1, 0)
      continue
    
    e1, e2 = c[0], c[n - 1]
    b1, b2 = 1, 1
    while b1 + b2 < n:
      if e1 < x * e2:
        e1 += c[b1]
        b1 += 1
      elif e1 > x * e2:
        b2 += 1
        e2 += c[n - b2]
      else: #e1 == x * e2:
        if b1 >= b2:
          e1 += c[b1]
          b1 += 1
        else: #b1 < b2:
          b2 += 1
          e2 += c[n - b2]

    print(b1, b2)

if __name__ == "__main__":
  main()
