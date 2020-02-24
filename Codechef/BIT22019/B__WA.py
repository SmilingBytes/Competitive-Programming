import sys


def main():
  sys.stdin = open('in.txt', 'r') 
  sys.stdout = open('out.txt', 'w')
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
    for i in range(1, n - 1):
      if b1 + b2 == n:
        break

      if e1 < x * e2:
        e1 += c[i]
        b1 += 1
      elif e1 > x * e2:
        b2 += 1
        e2 += c[n - b2]
        i -= 1
      else: #e1 == x * e2:
        if b1 >= b2:
          e1 += c[i]
          b1 += 1
        else: #b1 < b2:
          b2 += 1
          e2 += c[n - b2]
          i -= 1
    print(b1, b2)

if __name__ == "__main__":
  main()
