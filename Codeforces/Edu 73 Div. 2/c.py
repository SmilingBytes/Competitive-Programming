import sys


def main():
  #sys.stdin = open('in.txt', 'r') 
  # sys.stdout = open('out.txt', 'w')
  q = int(sys.stdin.readline())
  for _ in range(q):
    c, m, x = map(int, sys.stdin.readline().split())
    mn = min(c, m)
    t = c + m + x
    if t >= mn*3:
      print(mn)
    else:
      print(t//3)


if __name__ == "__main__":
  main()
